
#pragma once

#include <cstddef>

class mempool
{
    using mem_t = std::byte;

    mem_t * mem { nullptr };
    std::size_t capacity { 0 };
    std::size_t size { 0 };

    struct mem_barrier {
        mem_t * starting_address;
        std::size_t size;
    };

    mem_barrier bucket_1,
                bucket_4,
                bucket_8;
    
    void initialize_buckets();

public:
    mempool (const std::size_t, const bool align_to_long);
    
    mempool (const mempool&) = delete;
    mempool& operator= (const mempool&) = delete;

    mempool (mempool&&);
    mempool& operator= (mempool&&);

    ~mempool();

    void * allocate (const std::size_t);
    void deallocate(void *);

    inline std::size_t get_capacity() const { return capacity; }
    inline std::size_t get_size() const { return size; }
};
