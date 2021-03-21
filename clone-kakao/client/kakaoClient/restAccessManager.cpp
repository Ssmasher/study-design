#include "restAccessManager.h"

RestAccessManager& RestAccessManager::instance()
{
    static RestAccessManager i;
    return i;
}

QNetworkAccessManager* RestAccessManager::getManager()
{
    return mQnam.get();
}

RestAccessManager::RestAccessManager(QObject* parent) : QObject(parent) , mQnam(std::make_shared<QNetworkAccessManager>())
{

}
