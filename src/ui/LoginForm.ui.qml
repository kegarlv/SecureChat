import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4

Item {
    id: root

    width: parent.width
    height: parent.height

    signal loginClicked
    property alias username: usernameText.text
    property alias password: passwordText.text
    RowLayout {
        id: rowLayout
        x: 50
        y: 33
        width: 172
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            text: qsTr("Username")
            font.pixelSize: 12
        }

        TextInput {
            id: usernameText
            font.pixelSize: 12
            Layout.preferredHeight: 20
            Layout.preferredWidth: 80
        }
    }

    RowLayout {
        x: 54
        y: 90
        width: 172
        height: 40
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            text: qsTr("Password")
            font.pixelSize: 12
        }

        TextInput {
            id: passwordText
            font.pixelSize: 12
            Layout.preferredHeight: 20
            Layout.preferredWidth: 80
        }
    }

    Button {
        id: loginButton
        y: 208
        height: 44
        text: qsTr("Login")
        anchors.horizontalCenter: parent.horizontalCenter
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        onClicked: root.loginClicked()
    }
}
