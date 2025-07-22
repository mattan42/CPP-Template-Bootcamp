# Stage 2 - If it walks like a duck, and it talks like a duck, is it really a duck?

Let's take a look at a piece of code that uses the `Max` function template and `Buffer` class template we've written in the previous stage:

```c++
Buffer<int, 1> b1;
b1.data[0] = 1;

Buffer<int, 1> b2;
b2.data[0] = 2;

max<Buffer<int, 1>>(b1, b2);
```

Trying to compile this code results in the following compilation error:

```
In file included from /.../cpp_template_tutorial/Stages/1/main.cpp:5:
/.../cpp_template_tutorial/Stages/1/./solution/solution.hpp: In instantiation of ‘T max(T, T) [with T = Buffer<int, 1>]’:
/.../cpp_template_tutorial/Stages/1/main.cpp:96:24:   required from here
/.../cpp_template_tutorial/Stages/1/./solution/solution.hpp:7:12: error: no match for ‘operator>’ (operand types are ‘Buffer<int, 1>’ and ‘Buffer<int, 1>’)
    7 |     if (v1 > v2)
      |         ~~~^~~~
```

The compiler tells us:
- I've tried instantiating the function template `max` with the *type template parameter* `T` being `Buffer<int, 1>`.
- I can't seem to find an implementation for the `>` operator for `Buffer<int, 1>` and `Buffer<int, 1>`.

While we could've predicted that this won't work (we've written both `max` and `Buffer` and we know we don't have logic of comparing `Buffer` with anything), we didn't add any check to prevent this situation.

In this case, the compiler resulted in an error. However, the compiler has several operations it can perform before failing. The "worst" of them are the implicit operations.

In the solution of the previous stage, you can see we've instantiated the `max` function template with `bool`, and it worked. The compiler can apparently use the `>` operand on bools.

So this is an even worst case - the compiler allows this weird behavior, but do *we* want to allow this behavior?

> [!NOTE]
> In general, we should only explicitly allow the operations we support and "block" undefined / unsupported operations in order to prevent undefined / uncaught behavior.
> In other words, we should think in terms of "whitelist" and not "blacklist".

## Objective

1. Read about "duck typing" and answer:
    - In the context of c++ templates, what is "duck typing"?
    - What are the advantages of duck-typing?
    - What are the disadvantages of duck-typing?
    - How can we overcome duck-typing and enforce our type checks?
2. Find a way to "block" our `max` function template from receiving `bool` as it's *type template parameter* (prevent the scenario from being able to compile, provide a nice *intentional* wraning)
3. We can do better - Find a way to limit the types our `max` function template receives to only integral types.

<spoiler>
Hint: Look at the `type_traits` library (a part cpp's standard library).
</spoiler>

