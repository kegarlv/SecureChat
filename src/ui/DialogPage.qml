import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import MessageList 1.0

Page {
    id: root
    property string inConversationWith
    property int dialogId

    Timer {
        id: timer
    }

    header: ToolBar {
        ToolButton {
            text: qsTr("Back")
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: { root.StackView.view.pop(); backend.destroyDialog(dialogId);}
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
            model: backend.getMessages(dialogId)
            onCountChanged: {
                listView.currentIndex = count - 1
            }
            delegate: Column {
                spacing: 6
                readonly property bool sentByMe: author !== backend.getUsername();
                anchors.right: !sentByMe ? parent.right : undefined

                Row {
                    id: messageRow
                    spacing: 6
                    anchors.right: !sentByMe ? parent.right : undefined

                    Image {
                        id: avatar
                        source: "qrc:/" + dialogId.toString()
                    }
                    Rectangle {
                        id: rect
                        width: Math.min(messageText.implicitWidth + 24,
                                        listView.width - (!sentByMe ? avatar.width + messageRow.spacing : 0))
                        height: messageText.implicitHeight + 24
                        color: sentByMe ? "lightgrey" : "steelblue"

                        Label {
                            id: messageText
                            text: message;
                            color: sentByMe ? "black" : "white"
                            anchors.fill: parent
                            anchors.margins: 12
                            wrapMode: Label.Wrap
                        }
                    }
                }

                Label {
                    id: timestampText
                    text:  timestamp
                    color: "lightgrey"
                    anchors.right: sentByMe ? parent.right : undefined
                }
            }

            ScrollBar.vertical: ScrollBar {
                id:scrollBar
            }
        }

        Pane {
            id: pane
            Layout.fillWidth: true

            RowLayout {
                width: parent.width

                TextArea {
                    id: messageField
                    Layout.fillWidth: true
                    placeholderText: qsTr("Enter text...")
                    wrapMode: TextArea.Wrap
                }

                Button {
                    id: sendButton
                    text: qsTr("Send")
                    enabled: messageField.length > 0
                    onClicked: {backend.sendMessage(dialogId,messageField.text); messageField.text = "";}
                }
            }
        }
    }
}

