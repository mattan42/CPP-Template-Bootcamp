# Solution

## Explicit Specialization and `is_human`

According to "cppreference":
> Allows customizing the template code for a given set of template arguments.

Meaning, we can customize our `is_human` *class (struct) template* code based on the *type template parameter* we receive.

If this *type template parameter* is `Child`, `Baby` or `Adult`, we would set our `static constexpr bool value` to be `true`. Otherwise, our default implementation would have a `static constexpr bool value = false`.

First of all, we have to define the "normal" template (which is refferred to as the "primary template"). This is done the same way we defined *class tempaltes* before -

```c++
template<typename Human>
struct is_human
```

After having the primary template the compiler can result to (in case of no other match), we can have specializations - specialized code for a specific set of template parameters.

The syntax is a bit confusing:

```c++
template<>
struct is_human<Adult>
```

This is a full specialization for the `is_human` *class template* for the `Adult` type. We explicitly customize the code of `is_human` just if the type `Adult` was used to instantiate it.

> [!NOTE]
> The compiler will **always** try to choose the most "specialized specialization", the best fitting one.
> It's true that `Adult` is a type that can also fit in the primary template, but since we defined a specialization just for the `Adult` type, the compiler would prefer choosing this over the primary template.

So now we just have to create specializations for `Baby` and `Child` and implement the specializations and primary template:

```c++
// Primary should have a value = false implementation.
template<typename Human>
struct is_human
{
    static constexpr bool value = false;
};

// Specializations should have a value = true implementation
{
    static constexpr bool value = true;
};
```

Note that the solution provided does some little tricks to help make things more readable and prevent code duplication.

## `std::true_type` and `std::false_type`.

We can inherit publicly from either `true_type` or `false_type` to have the `static constexpr bool value` public member form the inheritence.

This helps making the code more readable, shorter and cleaner.

Another small feature we can utilize is the fact that we don't have to give a parameter name to the *template parameters*:

For example, in our primary template:

```c++
template<typename>
struct is_human : public std::false_type {};
```

We don't really need to do anything with the type the primary template receives, so we can just tell the compiler "I'm letting you know that this *class template* has to accept a *type template parameter*, but I don't need to actually use it in this context, so I don't bother giving it a name".

This is exactly equivelant to giving it a name, but it helps us convey the intention behind our code. We're basicallyl saying - the type does not relevant to me here. I know it's not a "Human" because it reached the default case.

> [!NOTE]
> In general, this feature of not having to name parameters is not limited just to templates. The standard doesn't force us to name parameters in function too, for example.


## `is_human_v`

This is a syntax sugar allowed using c++14's *variable template* feature. We can have `constexpr` variable values to be decided using *template parameters*.

> [!NOTE]
> The `_v` stands for `value`. This is a standard naming scheme, and especially in template code, in which it can get very complicated to understand if we're talking about a value or a type, it is recommended to adopt this standard.

```c++
template<typename Human>
constexpr bool is_human_v = is_human<Human>::value;
```

> [!NOTE]
> while The *template parameter name* `T` that's being used commonly in template code can be used here, it's better to use a more indicative name if appropriate.

So in this case, we would just have `is_human_v` to be a *variable template* that accepts a `typename Human`, feed it our `is_human` type trait, and extract the `bool` value using `::value` on the `is_human` type trait.

> [!NOTE]
> You may also have encountered the `_t` naming convention. This stands for `typename`, and it helps us understanding that the name we're looking at is a type, not a value.

## What have we Learned?

- Explicit (full) Template Specialization
    - What is referred to by "Primary Template"
    - Syntax of primary template and full specializations
- Creating our own type traits using full specializations
- Using *variable templates* (`template<...> constexpr bool is_human_v = ...`, in this stage)
