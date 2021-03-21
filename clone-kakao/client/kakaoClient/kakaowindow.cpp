#include "kakaowindow.h"

#include <QDebug>
#include <QQmlContext>

#include "viewStatusController.h"

KakaoWindow::KakaoWindow(QString qmlPath) : QQmlApplicationEngine(nullptr)
{
    init();
    setRootContext();
    load(QUrl(qmlPath));
}

bool KakaoWindow::isValidObject()
{
    return !rootObjects().isEmpty();
}

void KakaoWindow::init()
{

}

void KakaoWindow::setRootContext()
{
    this->rootContext()->setContextProperty("ViewStatusController", &ViewStatusController::instance());
}
