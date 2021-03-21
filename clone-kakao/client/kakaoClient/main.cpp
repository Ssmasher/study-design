#include <QGuiApplication>
#include "kakaowindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    KakaoWindow window("qrc:/MainWindow.qml");
    if (!window.isValidObject()) {
        return -1;
    }

    return a.exec();
}
