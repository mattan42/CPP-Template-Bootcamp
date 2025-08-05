# Stage 2 - Solution

## Duck Typing

**So what is duck typing?**

From the "duck typing" wikipedia article:

> In computer programming, duck typing is an application of the duck test—"If it walks like a duck and it quacks like a duck, then it must be a duck"—to determine whether an object can be used for a particular purpose.

**Ok, so what is duck typing in our context?**

In our `max` *function template* (from stage 1) we ask for a `T` *type tempalte parameter*. The only requirement on that `T` *type template parameter* is to be a c++ type (we can't, for example, write the literl `10` to be this parameter)

However, inside of our `max` *function tempalate*, we assume quite a lot of things:

1. `T` is "copy constructible".
    - For example, if `T` is a user-defined class type `Person` that has deleted it's copy constructor, our code won't compile - the compiler can't copy the instance of `T` to the function.

> [!NOTE]
> Even if you've implemented the `max` *function template* in stage 1 with `&` or `&&`, then it's not an assumption you took, but did you did not take that assumption *deliberately*?

2. `T` can be used with the `<` operator with another instance of itself (of `T`), *and* the operator returns `bool`.

This is a very dangerous assumption. If `T` has implemented the `<` operator with another instance of the same type, then we're good. It means that the developer thought that the user might want to compare two instances of the `T` type and implemented the scenario.

However, if the user didn't implement that operator - we're in the grace of the compiler. If `T` can be implicitly converted to a type that can be compared using `<`, then the compiler could implicitly convert the instances and use the operator.

If the developer hasn't took into consideration this case, then we're at undefined behvaiour territory.

The good case is that the compiler couldn't perform an implicit cast and thus results in an error, saying he can't use the operator `<` on `T` with `T` (with itself).

This is a good example of "duck-typing" - we assume that `T` can behave like we want it to, and let the compiler check (in compile time) if the user provided `T` type can behave like we wanted to or not.

**Advantages of duck typing**

The main advantage of duck typing is simpler development of template code - we can let the compiler do the hard work of checking if a template instantiation can be compiled (and thus can be run).

As you would see, manipulating types in a template context can be a quite difficult task, and so relying on the compiler to do the "hard work" for us is not necessarily a bad thing.

**Disadvantages of duck typing**

Duck typing can often result in an undefined behaviour.

Letting the compiler check things itself can also be a bad thing. Since we're not as smart as our compiler, we often times won't think of all the different scenarios the compiler is programmed to walk through.

Referencing to the example of the `max` function, if `T` is implicitly castable to an integer type that might *not be a good representation for comparison operations*, then we're at undefined territory. Our code will run, but won't work like we hope it would.

> [!NOTE]
> These advantages are specifically in a C++ templates context.

**How to overcome duck-typing?**

The question we should actually ask before is - "can we avoid duck-typing at all?"

The answer is no. C++ templates **are duck-typed by design**.

However, we can utilize an important asset in our toolbelt - the `static_assert` declaration.

This way, we can do those compiler checks ourselves and "fine tune" our requirements. As you can see, this was the objective of the current stage.

## Static Asserts

`static_assert` is a c++11 feature, as described in "cppreference":

> Performs compile-time assertion checking.
>
> ## Syntax
>
> `static_assert( bool-constexpr , unevaluated-string )`

As we can see, this `static_assert` declaration (which is like a function call, but this is a compile-time feature, so this is not *really* a function call) accepts:
- a boolean constexpr
- An unevaluated-string. We would ignore the "unevaluated" aspect at the moment - a string.

If the `bool-constexpr` is a `false` expression, then the compilation will fail and our string will be printed as a message.

This let's us both:

- Write our own compile-time checks.
- Alert the user and assist him in realizing the error.

## Blocking `T` from being of type `bool`

We need to learn about one more important tool in our disposal - the `type_traits` library.

From "cppreference":

> Type traits define compile-time template-based interfaces to query the properties of types.

From this library, we'll "query" two different "compile-time template-based interfaces":

```c++
template< class T, class U >
struct is_same;
```

and:

```c++
template< class T >
struct is_integral;
```

These two (and all the other type traits) have a pretty standard usage. The type trait is a struct that has a static bool member `value` which stores the "result" of the query.

For example:

```c++
static_assert(std::is_same<bool, int>::value, "The two types are not the same type") 
```

In this case, `::value == false`, since bool and int are not the same type. This will cause a compilation error and display the message - *"The two types are not the same type"*.

## What did we Learn?

- *duck typing* in general and in the context of c++ template programming.
- The `static_assert` directive
    - How to use it with the `type_traits` library
    - How to alert the user on compilation failure
- The `type_traits` library's type queries
    - `std::is_same` - checks if two types are the same
    - `std::is_integral` - checks if a type is integral
- How to use the the type checks from `type_traits` library with `static_asserts` to fine-tune our type checks.
