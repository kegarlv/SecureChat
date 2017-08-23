import QtQuick 2.6
import QtQuick.Controls 2.0


ApplicationWindow {
    width: 540
    height: 960
    visible: true

    StackView {
        id: view
        anchors.fill: parent
        initialItem: ContactPage {
        }
    }
}
