import QtQuick 2.6
import QtQuick.Controls 2.1
import QtGraphicalEffects 1.0

Page {
    id: root

    header: ToolBar {
        ToolButton {
            text: "Settings";
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: root.StackView.view.push("qrc:/SettingsPage.qml")
        }

        Label {
            text: qsTr("Contacts")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }

    ListView {
        id: listView
        anchors.fill: parent
        topMargin: 48
        leftMargin: 48
        bottomMargin: 48
        rightMargin: 48
        spacing: 20
        model: ["Albert Einstein", "Ernest Hemingway", "Hans Gude"]
        delegate: ItemDelegate {
            text: modelData
            width: listView.width - listView.leftMargin - listView.rightMargin
            height: avatar.implicitHeight
            leftPadding: avatar.implicitWidth + 32
            onClicked: root.StackView.view.push("qrc:/DialogPage.qml", { inConversationWith: modelData })
            Image {
                id: avatar
                source: "qrc:/" + modelData + ".png"
            }
        }
    }
}

