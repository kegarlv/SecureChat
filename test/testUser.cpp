#include "gtest/gtest.h"
#include "../src/CurrentUser.h"

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
    ASSERT_FALSE(user->authorize());
}