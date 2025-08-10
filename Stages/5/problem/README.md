# Stage 4 - Substitution Failure is Not an Error!?

In the previous stages we've learned about *template specialization*, which is a compile feature allowing us to specify different implementations for the same template.

In previous stages (stage 1) we've also learned about the *instantiation* stage, in which the compiler actually creates the function from the *function template* (or class from the *class template*).

However, since these explanations (and even the following explanation) are a bold simplification of all the different steps the compiler does, there is another crucial step we haven't talked about yet - "substitution".

Substitution, in the context of templates, is when the compiler tries switching the *template parameters* with *template arguments*; with actual values that would replace the parameters.

For example:

```c++
// T and MemberCount are *template parameters*.
template<typename T, int MemberCount>
class Buffer
{
public:
    T data[MemberCount];
};

Buffer<int, 1> my_buffer; // int and 1 are *template arguments*.
```

In this example, "substitution" is when the compiler tries taking `int`, `1` and put them as `typename T` and `int MemberCount`.

So what is SFINAE - Substitution Failure Is Not An Error?

## Objective

1. Read about
    - The [`decltype` Specifier](https://en.cppreference.com/w/cpp/language/decltype.html)
    - [SFINAE](https://en.cppreference.com/w/cpp/language/sfinae.html)
    - [`std::enable_if`](https://en.cppreference.com/w/cpp/types/enable_if.html)
    - [`declval`](https://en.cppreference.com/w/cpp/utility/declval.html)
2. Create a `is_human_like_v` type trait that results to `true` if a type has a public member `int age`.
3. Extend the `is_human_like_v` type trait to results to `true` if a type has a public member `int age` **or** a public method `age` that returns `int`.

> [!WARNING]
> This might be the hardest stage yet. It requires knowing the nitty-gritty of the template compilation process and understanding how to use it to our advantage. 
> 
> Don't give up quickly! A huge part of writing template code in c++ is fighting with the compiler until something works.
>
> Good luck!


## Limitations

- Do not modify the `main.cpp`.

> [!NOTE]
> You can comment tests in order to solve the stage step-by-step.

- Do not modify any of the files under `include`.
- Do not use c++20 features - concepts, contraints, `requires`, etc...
- Do not use c++17's `if constexpr` feature.
