#include "buffer.h"

template <typename T>
const std::vector<T>& Buffer<T>::getBuf() const
{
    return buf;
}

template <typename T>
void Buffer<T>::push(T param)
{
    unsigned capacity = buf.capacity();
    if(capacity == index) index = 0;
    buf[index] = param;
    index++;
}

template <typename T>
unsigned int Buffer<T>::getCurrentIndex() const
{
    return index;
}
