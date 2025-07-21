# Stage 1 - Templates Basics

## What are Templates?

Searching this question on google, the first page that pops up is a "geek for geeks" page. The first sentence goes as follows:

> C++ template is a powerful tool that allows you to write a generic code that can work with any data type. The idea is to simply pass the data type as a parameter so that we don't need to write the same code for different data types.

This is true, and while it should be the first thing that we learn, it covers only one (and rather "weak") use case of templates.

## Objective

As stated earlier, we'll begin by using the power of templates to write a generic code for multiple data types.

1. Create a `max` *function template* that accepts a *type tempalte parameter*.

2. Create a `Buffer` *class template* that accepts two *template parameter*s:
- A *type template parameter* which will hold the type of the members it will be able to store.
- A *constant template parameter* of an integral type, which will hold the number of members it will be able to store.

3. Create the `CONSTANT_BUFFER_SIZE` parameter the tests use. This parameter should contain the integral value `10`.

> [!WARNING]
> Do **not** use the pre-processor to declare this parameter.

> [!NOTE]
> As a general note, we should always prefer using tepmaltes as opposed to macros (the pre-processor). On on that in the "appendix" section.

## Extra Questions

1. Why is it called *function template* and not "template function"? How does it explain the behavior of the compiler?

> [!NOTE]
> Try reading [this page (from cppreference com)](https://en.cppreference.com/w/cpp/language/class_template.html#:~:text=Class%20template%20instantiation)
