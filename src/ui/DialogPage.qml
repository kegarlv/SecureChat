import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

import MessageList 1.0
import DialogController 1.0
import Message 1.0

Page {
    id: root
    property string inConversationWith
    property int dialogId

    DialogController {
        id:currDialog
        dialogID: dialogId
    }

    header: ToolBar {
        ToolButton {
            text: qsTr("Back")
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: { root.StackView.view.pop();}
        }
        Label {
            id: pageTitle
            text: inConversationWith
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }

    ColumnLayout {
        anchors.fill: parent

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: pane.leftPadding + messageField.leftPadding
            displayMarginBeginning: 40
            displayMarginEnd: 40
            spacing: 12
            model: {currDialog.dialogID = root.dialogId; currDialog.getMessageList()}
            onCountChanged: {
                listView.currentIndex = count - 1
            }
            delegate: MessageView {
                messageText: message
                timestamp: timestamp
                sentByMe: author !== "Ivan Voloshyn"
                //TODO
//                avatar: avatar
            }

            ScrollBar.vertical: ScrollBar {
                id:scrollBar
            }
        }

        MessageEditor {
            id: messageEditor
            onSendMessage: { currDialog.sendMessage(messageText);messageText = "";}
        }
    }
}

