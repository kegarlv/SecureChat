import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

Pane {
    signal sendMessage()
    property alias messageText: messageField.text

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
            onClicked: sendMessage()
        }
    }
}
