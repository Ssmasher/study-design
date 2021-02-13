#pragma once

#include <QtQml/QQmlApplicationEngine>

class KakaoWindow : public QQmlApplicationEngine
{
public:
    KakaoWindow(QString qmlPath);
    virtual ~KakaoWindow() = default;
    bool isValidObject();

private:
    void init();
    void setRootContext();
};
