import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
//    Rectangle {
//        id: root
//        width: 100; height: 100
//        state: "normal"
//        states: [
//            State {
//                name: "normal"
//                PropertyChanges { target: root; color: "green" }
//            },
//            State {
//                name: "red_color"
//                PropertyChanges { target: root; color: "red";width:150 }
//            },
//            State {
//                name: "blue_color"
//                PropertyChanges { target: root; color: "blue" ;height:150}
//            }
//        ]
//        MouseArea{
//            anchors.fill:parent
//            onPressed: {
//                root.state="red_color"
//            }
//            onReleased: {
//                root.state="blue_color"
//            }
//        }
//    }

//    Rectangle {
//        id: flashingblob
//        width: 75; height: 75
//        color: "blue"
//        opacity: 1.0//透明度

//        MouseArea {
//            anchors.fill: parent
//            onClicked: {
//                animateColor.start()
//                animateOpacity.start()
//                animateWidth.start()
//            }
//        }

//        PropertyAnimation {
//            id: animateColor;
//            target: flashingblob;
//            properties: "color";
//            to: "green";
//            duration: 1000
//        }

//        NumberAnimation {
//            id: animateOpacity
//            target: flashingblob
//            properties: "opacity"
//            from: 0.1
//            to: 1.0
//            duration: 2000

//        }
//        NumberAnimation {
//            id: animateWidth
//            target: flashingblob
//            properties: "width"
//            from: 75
//            to: 150
//            duration: 2000

//        }
//    }

    Rectangle {             //动画修改控件的位置
        id: rect
        width: 100; height: 100
        color: "red"

        PropertyAnimation on x {
            to: 100
            duration: 2000}
        PropertyAnimation on y {
            to: 100
            duration: 2000
        }
        PropertyAnimation on width {
            to: 400
            duration: 2000
        }
        PropertyAnimation on color {
            to: "yellow"
            duration: 2000
        }
    }
}
