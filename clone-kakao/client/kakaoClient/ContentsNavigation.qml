import QtQuick 2.0
import QtQuick.Controls 2.15

Rectangle {
    color: "lightgray"

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 30
        width: 50
        property int buttonHeight: 50

        Button {
            id: friends
            width: parent.width
            height: parent.buttonHeight

            background: Rectangle {
                anchors.fill: parent
                color: "lightgray"
            }

        }

        Button {
            width: parent.width
            height: parent.buttonHeight

            background: Rectangle {
                anchors.fill: parent
                color: "lightgray"
            }
        }

        Button {
            width: parent.width
            height: parent.buttonHeight

            background: Rectangle {
                anchors.fill: parent
                color: "lightgray"
            }
        }

    }

}
