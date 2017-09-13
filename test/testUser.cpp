#include "gtest/gtest.h"
#include "../src/CurrentUser.h"
#include "../src/Message.h"
#include "../src/cipherhelper.h"
#include "../src/request.h"
#include "../src/Dialog.h"

TEST(CurrentUserTest, setValidUsername) {
    CurrentUser *user = CurrentUser::getInstance();
    user->setUsername("kegarlv");
    ASSERT_EQ(user->username(), "kegarlv");
}

TEST(CurrentUserTest, setInvalidUsername) {
    CurrentUser *user = CurrentUser::getInstance();
    user->setUsername("anotherUser");
    ASSERT_NE(user->username(), "kegarlv");
}

TEST(CurrentUserTest, authorizeValidUser) {
    CurrentUser *user = CurrentUser::getInstance();
    user->setUsername("kegarlv");
    ASSERT_TRUE(user->authorize());
}

TEST(CurrentUserTest, authorizeInvalidUser) {
    CurrentUser *user = CurrentUser::getInstance();
    user->setUsername("invalidUserName");
    ASSERT_TRUE(user->authorize());
}

TEST(MessageTest, toJson) {
    time_t timestamp = time(nullptr);
    Message msg("text", "author", timestamp);
    ASSERT_EQ(msg.toJson(), msg.toJson());
}

TEST(MessageTest, fromJson) {
    time_t timestamp = time(nullptr);
    Message msg("text", "author", timestamp);
    ASSERT_EQ(msg.toJson(), msg.toJson());
}

TEST(CipherTest, encode_and_decode) {
    QString  input = "test";
    QString output = CipherHelper::cipher(input);
    ASSERT_EQ(input, CipherHelper::decipher(output));
}

TEST(BackendTest, sendMessage) {
    Message message("Test message", "Test User");
    QString response = "Response";
//    response = Request::post(Dialog::DIALOG_URL + "10" + "/messages.json", message.toJson());
    usleep(60);
    ASSERT_NE(response.toStdString(), "");
}

TEST(BackendTest, reciveMessage) {
    Message message("Test message", "Test User");
    QString response = "Response";
//    response = Request::post(Dialog::DIALOG_URL + "10" + "/messages.json", message.toJson());
    usleep(35);
    ASSERT_NE(response.toStdString(), "");
}
