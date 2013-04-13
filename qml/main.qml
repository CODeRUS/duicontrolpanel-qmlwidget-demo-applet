import Qt 4.7
import QtQuick 1.1
import com.nokia.meego 1.1

Item {
    id: root
    height: column.height

    Column {
        id: column
        width: parent.width

        Rectangle {
            id: rectOne
            color: "red"
            width: parent.width
            height: 400
        }

        Rectangle {
            color: "green"
            width: parent.width
            height: 400

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    rectOne.color = QMLHelper.getRandomColor()
                }
            }
        }

        Rectangle {
            color: "blue"
            width: parent.width
            height: 400
        }
    }
}
