import QtQuick 2.0
import QtQuick.Controls 2.15

Row {
    id: loginWindowControl
    spacing: 10

    Button {
        id: hide
        y: 5
        font.pixelSize: 10
        text: "ㅡ"

        background: Rectangle {
            anchors.fill: parent
        }

        onClicked: mainWinow.showMinimized()
    }

    Button {
        id: setting
        text: "ㅁ"

        background: Rectangle {
            anchors.fill: parent
        }
    }

    Button {
        id: close
        y: 1
        text: "x"

        background: Rectangle {
            anchors.fill: parent
        }

        onClicked: mainWinow.close()
    }
}
