#pragma once

#include <mutex>
#include <queue>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class RestComponent : public QObject
{
    Q_OBJECT

public:
    enum class RestType
    {
        Get,
        Post,
        Max
    };

    explicit RestComponent(RestType _type, QObject* parent = nullptr);
    virtual ~RestComponent();

    void get(QNetworkRequest _req);
    void post(QNetworkRequest _req, QJsonObject _data);

signals:
    void notifyReadyRead(const QByteArray data);
    void notifyRedirected(const QUrl url);

private:
    void connections();
    void disconnections();
    void recursive();

private slots:
    void httpReadyRead();
    void sslErrors(const QList<QSslError>& _errors);
    void httpFinished();
    void httpRedirected(const QUrl& url);

private:
    std::mutex mMutex;
    RestType mType;
    bool mIsReady;

    std::queue<QNetworkRequest> mGetQueue;
    std::queue<std::pair<QNetworkRequest, QJsonObject>> mPostQueue;

    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> mReply;

    QNetworkAccessManager* mQnam;
};
