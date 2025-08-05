# Stage 4 - Substitution Failure is Not an Error!?

In the previous stage we've learned about *template specialization*, which is a compile feature allowing us to specify different implementations for the same template. The compiler will look at all the specialization and will look for the most "special" one.

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

1. Read about: ... TODO: This!
2. Create a `is_human_like` type trait that returns `true` if a type has a public member `int age`.
3. Create a `is_human_like` type trait that returns `true` if a type has a public member `int age` **or** a public method `age` that returns `int`.
