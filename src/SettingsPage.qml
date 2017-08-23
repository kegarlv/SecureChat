import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

Page {
    id: root
    header: ToolBar {
        ToolButton {
            text: "Back";
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: root.StackView.view.pop()
        }

        Label {
            text: qsTr("Settings")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }

}
