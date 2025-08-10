
#include <gtest/gtest.h>
#include "buffer.hpp"

#include "solution.hpp"

struct Alien {};

TEST(is_buffer, buffers)
{
    EXPECT_TRUE((is_buffer<Buffer<int, 1>>::value));
    static_assert(is_buffer<Buffer<int, 1>>::value, "A type Buffer<int, 1> should be considered a buffer");
}

TEST(is_buffer, not_buffers)
{
    EXPECT_FALSE(is_buffer<Alien>::value);
    static_assert(!is_buffer<Alien>::value, "A type Alien should not be considered a buffer");
}
