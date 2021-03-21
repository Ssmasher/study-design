#include "restComponent.h"

#include <QtNetwork>

#include "restAccessManager.h"

RestComponent::RestComponent(RestType _type, QObject* parent) : QObject(parent)
  , mType(_type), mIsReady(true), mQnam(RestAccessManager::instance().getManager())
{
}

void RestComponent::get(QNetworkRequest _req)
{
    std::lock_guard<std::mutex> lock(mMutex);

    if (mType == RestType::Get)
    {
        if (mIsReady) {
            mReply.reset(mQnam->get(_req));
            connections();
        } else {
            mGetQueue.push(_req);
        }
    }
    else
    {
        qDebug() << "this RestComponent type is not [get]";
    }
}

void RestComponent::post(QNetworkRequest _req, QJsonObject _data)
{
    std::lock_guard<std::mutex> lock(mMutex);

    if (mType == RestType::Post)
    {
        if (mIsReady) {
            mReply.reset(mQnam->post(_req, QJsonDocument(_data).toJson()));
            connections();
        } else {
            mPostQueue.push(std::make_pair(_req, _data));
        }
    }
    else {
        qDebug() << "this RestComponent type is not [post]";
    }

}

RestComponent::~RestComponent()
{
    this->disconnect();
}

void RestComponent::connections()
{
    mIsReady = false;
    connect(mReply.get(), &QNetworkReply::finished, this, &RestComponent::httpFinished);
    connect(mReply.get(), &QIODevice::readyRead, this, &RestComponent::httpReadyRead);
    connect(mReply.get(), &QNetworkReply::sslErrors, this, &RestComponent::sslErrors);
    connect(mReply.get(), &QNetworkReply::redirected, this, &RestComponent::httpRedirected);
}

void RestComponent::disconnections()
{
    this->disconnect();
    mReply.reset();
    mIsReady = true;
}

void RestComponent::recursive()
{
    if (mType == RestType::Get)
    {
        if (mGetQueue.size()) {
            this->get(mGetQueue.front());
            mGetQueue.pop();
        }
    }
    else if (mType == RestType::Post)
    {
        if (mPostQueue.size()) {
            this->post(mPostQueue.front().first, mPostQueue.front().second);
            mPostQueue.pop();
        }
    }
}

void RestComponent::httpFinished()
{
    std::lock_guard<std::mutex> lock(mMutex);

    qDebug() << Q_FUNC_INFO << ", object: " << this;

    disconnections();
    recursive();
}

void RestComponent::httpRedirected(const QUrl &url)
{
    qDebug() << Q_FUNC_INFO << url << this;
    emit notifyRedirected(url);
}

void RestComponent::httpReadyRead()
{
    qDebug() << Q_FUNC_INFO << ", object: " << this << mReply->readAll();
    emit notifyReadyRead(mReply->readAll());
}

void RestComponent::sslErrors(const QList<QSslError> &_errors)
{
    QString errorString;

    for (const QSslError &error : _errors) {
        if (!errorString.isEmpty())
            errorString += '\n';
        errorString += error.errorString();
    }

    qDebug() << Q_FUNC_INFO << errorString << ", object: " << this;
}

