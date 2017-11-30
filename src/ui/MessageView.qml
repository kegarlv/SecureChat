import QtQuick 2.0
import QtQuick.Controls 2.1


Column {
    property alias messageText: messageText.text
    property bool sentByMe: false
    property alias avatar: avatar.source
    property alias  timestamp: timestampText.text

    spacing: 6
    anchors.right: !sentByMe ? parent.right : undefined
    Row {
        id: messageRow
        spacing: 6
        anchors.right: !sentByMe ? parent.right : undefined

        Image {
            id: avatar
        }
        Rectangle {
            id: rect
            width: Math.min(messageText.implicitWidth + 24,
                            listView.width - (!sentByMe ? avatar.width + messageRow.spacing : 0))
            height: messageText.implicitHeight + 24
            color: sentByMe ? "lightgrey" : "steelblue"

            Label {
                id: messageText
                color: sentByMe ? "black" : "white"
                anchors.fill: parent
                anchors.margins: 12
                wrapMode: Label.Wrap
            }
        }
    }

    Label {
        id: timestampText
        color: "lightgrey"
        anchors.right: sentByMe ? parent.right : undefined
    }
}
