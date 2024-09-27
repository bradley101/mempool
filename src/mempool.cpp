
#include "mempool.hpp"

#include <algorithm>
#include <cmath>
#include <cstring>

mempool::mempool(
    const std::size_t capacity = 4096,
    const bool align_to_long = true) : capacity(capacity)
{
    if (align_to_long)
        this->capacity = std::ceil(capacity / 8) * 8;
    mem = (mem_t *) ::operator new(this->capacity);
    std::fill(mem, mem + this->capacity, 0);
}

mempool::~mempool()
{
    ::operator delete (mem);
}

mempool::mempool(mempool&& rhs) : mempool(rhs.capacity)
{
    std::memcpy(mem, rhs.mem, rhs.capacity);
    std::fill(rhs.mem, rhs.mem + capacity, 0);
    rhs.size = 0;
}

mempool& mempool::operator=(mempool&& rhs)
{
    std::memcpy(mem, rhs.mem, rhs.capacity);
    std::fill(rhs.mem, rhs.mem + capacity, 0);
    rhs.size = 0;
}

void mempool::initialize_buckets()
{}
