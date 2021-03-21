#include "viewStatusController.h"

#include <QtNetwork>
#include <QQmlEngine>

ViewStatusController::ViewStatusController(QObject *parent) : QObject(parent)
  , mViewStat(ViewStatus::Login)
  , mRestApiGet(RestComponent::RestType::Get) , mRestApiPost(RestComponent::RestType::Post)
  , mUrl("")
{
    qDebug() << "mRestApiGet" << &mRestApiGet << "mRestApiPost" << &mRestApiPost;

    init();
    connections();
}

ViewStatusController::~ViewStatusController()
{

}

ViewStatusController &ViewStatusController::instance()
{
    static ViewStatusController i;
    return i;
}

void ViewStatusController::requestLogin(QString _id, QString _password)
{
    QNetworkRequest req(QUrl("http://127.0.0.1:3000/auth/login"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject jsonData;
    jsonData["email"] = _id;
    jsonData["password"] = _password;

    qDebug() << Q_FUNC_INFO;

    mRestApiPost.post(req, jsonData);
}

void ViewStatusController::init()
{
    qmlRegisterType<ViewStatus>("ViewStatusEnums", 1, 0, "ViewStatus");
}

void ViewStatusController::connections()
{
    connect(&mRestApiPost, &RestComponent::notifyRedirected, this, &ViewStatusController::requestRedirected);
}

void ViewStatusController::requestRedirected(const QUrl url)
{
    qDebug() << Q_FUNC_INFO << url;

    mUrl = url;

    if (mUrl.path() == "/") {
        setViewStat(ViewStatus::FriendList);
    }
}

