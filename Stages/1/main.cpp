#include <stdlib.h>
#include <stdint.h>
#include <gtest/gtest.h>

#include "solution.hpp"

TEST(max, uint8)
{
    uint8_t v1 = 1;
    uint8_t v2 = 2;
    EXPECT_EQ(max(v1, v2), v2);
    EXPECT_EQ(max<uint8_t>(v1, v2), v2);
}

TEST(max, uint32)
{
    uint32_t v1 = 1;
    uint32_t v2 = 2;
    EXPECT_EQ(max(v1, v2), v2); 
    EXPECT_EQ(max<uint32_t>(v1, v2), v2); 
}

TEST(max, uint64)
{
    uint64_t v1 = 1;
    uint64_t v2 = 2;
    EXPECT_EQ(max(v1, v2), v2); 
    EXPECT_EQ(max<uint64_t>(v1, v2), v2); 
}

TEST(max, char)
{
    char v1 = 'a';
    char v2 = 'b';
    EXPECT_EQ(max(v1, v2), v2); 
    EXPECT_EQ(max<char>(v1, v2), v2); 
}

// NOTE: This is weird! But works??
TEST(max, bool)
{
    bool v1 = true;
    bool v2 = false;
    EXPECT_EQ(max(v1, v2), v1); 
    EXPECT_EQ(max<bool>(v1, v2), v1);  
}

TEST(buffer, bool)
{
    Buffer<bool, 2> bool_buffer;
    bool_buffer.data[0] = true;
    bool_buffer.data[1] = false;

    EXPECT_TRUE(bool_buffer.data[0]);
    EXPECT_FALSE(bool_buffer.data[1]);
}

TEST(buffer, uint8)
{
    Buffer<uint8_t, 2> bool_buffer;
    bool_buffer.data[0] = 0;
    bool_buffer.data[1] = 1;

    EXPECT_EQ(bool_buffer.data[0], 0);
    EXPECT_EQ(bool_buffer.data[1], 1);
}
