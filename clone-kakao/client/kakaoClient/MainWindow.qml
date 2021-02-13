import QtQuick 2.12
import QtQuick.Controls 2.15

Window  {
    id: mainWinow

    minimumWidth: 300
    minimumHeight: 500
    visible: true
    flags: (Qt.Window | Qt.FramelessWindowHint)
    color: "#F7E600"

    Item {
        id: dragControl
        width: parent.width
        height: 30

        MouseArea {
            anchors.fill: parent
            property variant clickPos: Qt.point(1,1)

            onPressed: {
                clickPos = Qt.point(mouse.x,mouse.y)
            }

            onDoubleClicked: {
                if (mainWinow.visibility === Window.Maximized) {
                    mainWinow.visibility = Window.AutomaticVisibility
                } else {
                    mainWinow.visibility = Window.Maximized
                }
            }

            onPositionChanged: {
                var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
                var new_x = mainWinow.x + delta.x
                var new_y = mainWinow.y + delta.y
                if (new_y <= 0)
                    mainWinow.visibility = Window.Maximized
                else
                {
                    if (mainWinow.visibility === Window.Maximized)
                        mainWinow.visibility = Window.Windowed
                    mainWinow.x = new_x
                    mainWinow.y = new_y
                }
            }
        }
    }

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: "qrc:/Login.qml"

        popEnter: Transition {}
        popExit: Transition {}
        pushEnter: Transition {}
    }

}
