#include "Utilities/assert.hpp"
#include "Utilities/util.hpp"

namespace dsa
{
    using size_t = unsigned long;

    //* Fixed-sized Array
    template<typename T, size_t size>
    class Array
    {
    private:
        using type = T;
        using reference = T&;
        using pointer = T*;
        
        using const_type = const T;
        using const_reference = const T&;
        using const_pointer = const T*;

    public:

        //*
        template<typename... Args>
        constexpr Array(Args&&... args) noexcept
        {
            size_t i = 0;
            ((data_[i++] = T(forward<Args>(args))),...);
        }

        constexpr reference operator[](size_t index)
        {
            ASSERT(index < size, "Index out of points!");
            return data_[index];
        }

        constexpr const_reference operator[](size_t index) const
        {
            ASSERT(index < size, "Index out of points!");
            return data_[index];
        }

        constexpr size_t getSize() const { return size; }

    private:
        T data_[size];

    };

    //* Dynamic array
    template<typename T, size_t size = 0>
    class DArray
    {
    private:
        using type = T;
        using reference = T&;
        using pointer = T*;
        
        using const_type = const T;
        using const_reference = const T&;
        using const_pointer = const T*;

    private:
        size_t size_;
        size_t capacity_;
        pointer data_;

    };

}