#include "gtest/gtest.h"

#include "../src/structs/Message.h"

TEST(MessageTest, sgAuthor) {
    Message msg;
    QString author = "author";
    msg.setAuthor(author);
    ASSERT_EQ(author, msg.getAuthor());
}

TEST(CurrentUserTest, setValidUsername2) {
    Message msg;
    ASSERT_EQ(1,0);
}

