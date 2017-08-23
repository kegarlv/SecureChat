#include <iostream>
#include <thread>
#include <exception>

#include "CurrentUser.h"
#include "Message.h"

#include "Dialog.h"

#include <unistd.h>

int main() {

    CurrentUser *user = CurrentUser::getInstance();
    std::cout << "Enter username: ";
    std::string username;
    std::cin >> username;
    user->setUsername(username);
    user->authorize();

    int dialogId;
    std::cout << "Enter dialogId (enter 1 for test dialog): ";
    std::cin >> dialogId;
    Dialog *dialog = user->createDialog(dialogId);

    std::thread FetchThread([dialog] {
        try {
            while (1) {
                auto messages = dialog->dumpMessages();
                system("clear");

                for (auto msg : messages) {
                    std::cout << msg.toHuman() << std::endl;
                }
                sleep(1);
            }
        } catch (std::exception &e) {
            std::cout << e.what();
        }
    });

    std::string message;
    try {
        while (1) {
            std::getline(std::cin, message);
            dialog->writeMessage(message);
        }
    } catch (std::exception &e) {
        std::cout << e.what();
    }

    return 0;
}
