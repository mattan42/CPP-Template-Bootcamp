# Stage 1 Solution

## The `max` *function template*

Altough a very simple implementation, this function helped us to get familiar with the syntax of writing *function template*s in c++.

From "cppreference.com":
```c++
template < parameter-list > function-declaration
```

And we got ourself familiary with one type of *template parameter* - the *type template parameter*:
```c++
template<typename NAME> function-declaration
```

> [!NOTE]
> If you've used `class` (instead of `typename`) it's perfectly fine - there's no difference between them in this case.


## The `Pair` *class template*

The same as before, the implementation is not hard, but we got ourself familiary with writing *class template*s:

```c++
template < parameter-list > class-declaration
```

Which is practically the same as with *function template*s.

## Defining `CONSTANT_BUFFER_SIZE` without macros

If you've just used `const`, you've probably encountered a compiler error.

This is because even if variables are marked as `const` in c++, we do have `const_cast` that we can use to remove the const and change the value. Meaning, the value *can* in fact change.

Templates are resolved in compile-time, so for that reason, everything that has to be known at compile time *has to be known at compile time*.

Since we try to use `CONSTANT_BUFFER_SIZE` as a *integral type constant tempalte parameter*, it has to be known at compile time. But just marking a variable as `const` doesn't require it to be known at compile time.

For that reason, we have the `constexpr` specifier. From cppreference:
> The constexpr specifier declares that it is possible to evaluate the value of the entities at compile time.

For us to use an *integral type constant tempalte parameter*, the value has to be *constant* and known in compile time - so this keyword specifier is necessary in this case.

However, keep in mind that the `constexpr` can be useful in plenty of other use-cases we'll see in later stages.

## Extra Questions

1. Why is it called *function template* and not "template function"? How does it explain the behavior of the compiler?

The correct term (which you see around documentation sites like "cppreference"), is *function template* and *class template*, because it's not a class in itself.

If it were to be called "template class", then it means that it is some kind of class; a "template" class. But it's not - it's a template for classes, a "class template".

From "cppreference":
> A class template by itself is not a type, or an object, or any other entity. No code is generated from a source file that contains only template definitions. 

From this sentence we can infer that *class template*s (and *function tempalte*s) are strictly a compiler "feature"; it will "change" to a type, or object, or other c++ entity in compile time.

This is a good point in all things concerning templates - **templates are a compile-time feature**.

> In order for any code to appear, a template must be instantiated: the template arguments must be provided so that the compiler can generate an actual class (or function, from a function template).

In other words, only when we actually try to use the *class template* / *function template* (when we used the `max` function for example), then the compiler actually *instantiates* a function. For each different *template parameter list*, a different *instantiation* will be created.

This is called **implicit instantiation**, since we don't explicitly instantiate the class / function ourself but rather just using it, causing the compiler to instantiate it implicitly.

## What We've Learned

- Declaring and using **function templates**
- Declaring and using **class tempaltes**
- Two types of **template parameters**
    - **integral type constant template parameter**
    - **type template parameter** (`typename` / `class`)
- How the compiler handles templates (**implicit instantiation**).
- Using the **`constexpr`** modifier (in the context of *integral type constant template parameter*)
