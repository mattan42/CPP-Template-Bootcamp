# Stage 4 - Partial Specializations

In the last stage we've learned how to write full template specializations and implemented our own `is_human` type-trait.

Remember our `Buffer` *class template* from the first stage? If we want to write a type-trait for this... type? (is it really a type?) using full template specialization, that would be impossible... We can't specify all the cases for each valid instantiation of `Buffer`...

```c++
template<typename>
struct is_buffer : public std::false_type {};

template<>
struct is_buffer<Buffer<int, 1>> : public std::false_type {};

template<>
struct is_buffer<Buffer<int, 2>> : public std::false_type {};

template<>
struct is_buffer<Buffer<int, 3>> : public std::false_type {};

// Impossible, right?
```

In order to still have a `is_buffer` type trait, which is in other words a type trait that checks if a type is an instantiations of a certain template, we would have to use *partial template specialization*.


## Objective

Read about [*partial template specializations*](https://en.cppreference.com/w/cpp/language/partial_specialization.html).

Create a `is_buffer` type trait that checks if a given type is a `Buffer`... type??? (is `Buffer` even a type? how can we check if something is created from the `Buffer` *class template*?)

## Limitations

- Do not modify the `main.cpp`.

> [!NOTE]
> You can comment tests in order to solve the stage step-by-step.

- Do not modify any of the files under `include`.
- Do not use c++20 features - concepts, contraints, `requires`, etc...
- Do not use c++17's `if constexpr` feature.