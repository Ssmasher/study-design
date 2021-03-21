#pragma once

#include <QObject>

#include "kCodeHelper.h"
#include "restComponent.h"

class ViewStatusController : public QObject
{
    Q_OBJECT

public:
    explicit ViewStatusController(QObject *parent = nullptr);
    virtual ~ViewStatusController();

    static ViewStatusController& instance();

    enum class ViewStatus
    {
        Login,
        FriendList,
        ChatList,
        Max
    };
    Q_ENUM(ViewStatus)

    DEFINE_QML_PROPERTY(ViewStatus, ViewStat)

public:
    Q_INVOKABLE void requestLogin(QString _id, QString _password);

private:
    void init();
    void connections();

private slots:
    void requestRedirected(const QUrl url);

private:
    RestComponent mRestApiGet;
    RestComponent mRestApiPost;

    QUrl mUrl;
};
