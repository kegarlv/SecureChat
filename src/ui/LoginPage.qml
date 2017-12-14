import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

import UserController 1.0

ApplicationWindow {
    id: root
    width: 300
    height: 300
    visible: true

    UserController {
        id: userController
    }

    Connections {
        target: userController
        onAuthorized: {
            if(isAuthorized) {
                console.log("Authorized");
                var component = Qt.createComponent("main.qml");
                var win = component.createObject(this);
                win.show();
            }
                root.close();
        }
    }

    LoginForm {
        id: loginForm
        onLoginClicked: {
            console.log("Logged in " + loginForm.username);
            loginForm.visible = false;
            spinner.visible = true;
            //TODO add password
            userController.auth(loginForm.username);
        }
    }

    BusyIndicator {
        id: spinner
        visible : false
        width: parent.width/2
        height: parent.height/2
        x: parent.width/4
        y: parent.height/4
    }
}
