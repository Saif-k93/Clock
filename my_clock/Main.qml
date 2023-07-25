
import QtQuick
import QtQuick.Window

import currenttime.h


Window {
    width: 500
    height: 400
    visible: true
    title: qsTr("Hello World")

    CurrentTime {
        id: currentTime

    }

    Image {
        id: img
        source: "images/clock.png"
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
        scale: .5


        Rectangle {
            id: big_nudle

            width: 10
            height: 200
            color: "gray"
            border.color: "black"
            border.width: 3
            radius: height
            anchors {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
                verticalCenterOffset: -105
                horizontalCenterOffset: 2
            }
            transform: Rotation { origin.x: big_nudle.width / 2; origin.y: 205; angle: currentTime.timeS * 6}
        }

        Rectangle {
            id: small_nudle

            width: 10
            height: 140
            color: "gray"
            border.color: "black"
            border.width: 3
            radius: height
            anchors {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
                verticalCenterOffset: -72
                horizontalCenterOffset: 2
            }
            transform: Rotation { origin.x: small_nudle.width / 2; origin.y:145; angle: (currentTime.timeH - 12) * 30}

        }
    }


}
