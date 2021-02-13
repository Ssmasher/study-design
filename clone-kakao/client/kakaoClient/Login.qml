import QtQuick 2.0
import QtQuick.Controls 2.15

Rectangle {
    color: "#F7E600"

    Row {
        id: loginWindowControl
        anchors.right: parent.right
        anchors.rightMargin: 10
        z: 1
        spacing: 10

        Button {
            id: setting
            text: "s"

            background: Rectangle {
                anchors.fill: parent
                color: "#F7E600"
            }
        }

        Text {
            id: space
            y: 10
            text: "|"
            color: "gray"
            opacity: 0.3
            font.pixelSize: 10
        }

        Button {
            id: hide
            y: 5
            font.pixelSize: 10
            text: "ㅡ"

            background: Rectangle {
                anchors.fill: parent
                color: "#F7E600"
            }

            onClicked: mainWinow.showMinimized()
        }

        Button {
            id: close
            text: "x"
            background: Rectangle {
                anchors.fill: parent
                color: "#F7E600"
            }

            onClicked: mainWinow.close()
        }
    }


    Image {
        id: logo
        anchors.horizontalCenter: parent.horizontalCenter
        y: 70
        width: 100
        height: 100
        source: "qrc:/image/kakaoLogo.png"
    }

    TextField {
        id: idField
        anchors.top: logo.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter

        width: 200
        height: 20
    }

    TextField {
        id: pwdField
        anchors.top: idField.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        width: 200
        height: 20
        echoMode: TextInput.Password
    }

    Button {
        anchors.top: pwdField.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 20

        font.pixelSize: 10
        text: "로그인"

        background: Rectangle {
            anchors.fill: parent
            color: 4 <= pwdField.length ? "lightblue" : "lightgray"
        }

        onClicked: loginInfoChecker()

        function loginInfoChecker() {
            // #TODO
            stack.push("qrc:/ContentsView.qml")
        }

    }


}
