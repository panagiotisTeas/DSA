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

        //* Default Constructor (Fills with 0's)
        constexpr Array() noexcept
        {
            for (size_t i = 0; i < size; i++)
                data_[i] = 0;
        }

        //* Constructor with variadic arguments
        template<typename... Args>
        constexpr Array(Args&&... args)
        {
            ASSERT(size == sizeof...(args), "List is not the same size as the defined array");
            size_t i = 0;
            ((data_[i++] = T(forward<Args>(args))),...);
        }

        //* [] operator overload 
        constexpr reference operator[](size_t index)
        {
            ASSERT(index < size, "Index out of points!");
            return data_[index];
        }

        //* [] operator overload (const version)
        constexpr const_reference operator[](size_t index) const
        {
            ASSERT(index < size, "Index out of points!");
            return data_[index];
        }

        //* Return size of array
        constexpr size_t getSize() const noexcept { return size; }

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