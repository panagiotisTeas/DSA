namespace dsa
{
    //* remove_reference does the following transformation
    //* T, T& (lvalue reference), T&& (rvalue reference) -> T 

    //* T -> T
    template<typename T>
    struct remove_reference
    {
        typedef T type;
    };

    //* T& -> T
    template<typename T>
    struct remove_reference<T&>
    {
        typedef T type;
    };

    //* T&& -> T
    template<typename T>
    struct remove_reference<T&&>
    {
        typedef T type;
    };

    //* Returns an rvalue reference
    //* Used for ownership movement
    template<typename T>
    typename remove_reference<T>::type&& move(T&& args) noexcept
    {
        return static_cast<typename remove_reference<T>::type&&>(args);
    }

    //* forward returns lvalues or rvalues depending on the argument
    //* Used for function arguments forwording in templates
    //* T& && -> T&, T& & -> T&, T&& & -> T&&, T&& && -> T&&
    template<typename T>
    T&& forward(typename remove_reference<T>::type& args) noexcept
    {
        return static_cast<T&&>(args);
    }

    template<typename T>
    T&& forward(typename remove_reference<T>::type&& args) noexcept
    {
        return static_cast<T&&>(args);
    }

}