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

// NOTE: Make sure to define CONSTANT_BUFFER_SIZE to contain the value "10" without the pre-processor.
// (`#define CONSTANT_BUFFER_SIZE 10` is not allowed!)
TEST(buffer, constant_sized_integral_buffer)
{
#ifdef CONSTANT_BUFFER_SIZE
#error "Please don't use macros to define CONSTANT_BUFFER_SIZE! use C++ features!"
#endif

    Buffer<uint32_t, CONSTANT_BUFFER_SIZE> int_buffer;
    EXPECT_EQ(sizeof(int_buffer.data), 10 * sizeof(uint32_t));
}
