import QtQuick 2.6
import QtQuick.Controls 2.1

Item {
    property alias text: messageText.text
    property alias timestamp: timestampText.text

    property alias avatar: avatar.source
    property bool sentByMe: false

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
