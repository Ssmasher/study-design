import QtQuick 2.0

Rectangle {

    ContentsViewFlag {
        anchors.right: parent.right
        anchors.rightMargin: 10
        z: 1
    }

    ContentsNavigation {
        id: navigation
        width: 50
        height: parent.height
    }

    ContentsChat {
        anchors.left: navigation.right
        width: parent.width - navigation.width
        height: parent.height
    }


}
