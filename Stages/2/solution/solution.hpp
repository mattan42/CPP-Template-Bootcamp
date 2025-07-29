#ifndef SOLUTION_HPP
#define SOLUTION_HPP

template<typename T>
T max(T v1, T v2)
{
    static_assert(!std::is_same<T, bool>::value, "This function template does not support instantiation with bool as the comparable type.");

    /**
     * This is also possible! It's just a syntax sugar that was introduced in c++17.
     */ 
    // static_assert(!std::is_same_v<T, bool>, "This function template does not support instantiation with bool as the comparable type.");

    static_assert(std::is_integral<T>::value, "This function template does not support instantiations of type T which is not an integral type.");

    if (v1 > v2)
        return v1;
    else
        return v2;
}

#endif