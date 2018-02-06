#ifndef BUFFER_H
#define BUFFER_H
#include <vector>
#include <iostream>

template <typename T>
class Buffer
{
public:
    Buffer(unsigned capacity) : buf(capacity,T()), index(0) {}
    const std::vector<T>& getBuf() const;
    void push(T param);
    unsigned int getCurrentIndex() const;
private:
     std::vector<T> buf;
     unsigned int index;
};

#endif // BUFFER_H
