#ifndef BUFFER_HPP
#define BUFFER_HPP

template<typename T, int MemberCount>
class Buffer
{
public:
    T data[MemberCount];
};

#endif