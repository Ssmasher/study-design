#pragma once

#include <QNetworkAccessManager>

class RestAccessManager : public QObject
{
    Q_OBJECT

public:
    static RestAccessManager& instance();
    QNetworkAccessManager* getManager();

private:
    explicit RestAccessManager(QObject* parent = nullptr);

    RestAccessManager(const RestAccessManager&) = delete;
    RestAccessManager(const RestAccessManager&&) = delete;
    RestAccessManager operator=(const RestAccessManager&) = delete;
    RestAccessManager operator=(const RestAccessManager&&) = delete;

    std::shared_ptr<QNetworkAccessManager> mQnam;
};
