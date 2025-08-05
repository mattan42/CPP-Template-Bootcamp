# Stage 3 - Specializations

In the last stage we've seen a good usage of the `type_traits` library - while we have no choice but accepting a generic type `T` to our function template or class template, we can enfore the compiler to accept only types that answer our critiques.

However, when our code-bases get more and more complex, we might want to have type-checks on types we've developed ourselves. For example, if we have `Adult`, `Child`, `Baby` classes, and we want to accept a `typename HumanType`, we need to have a custom "type_trait" check `is_human<HumanType>`.

This is what we'll do in this stage!

## Objective

1. Read about [*explicit (full) template specialization*](https://en.cppreference.com/w/cpp/language/template_specialization.html).
2. Create a `is_human` type trait that accepts a *type template parameter* and checks if the received *type template parameter* is an `Adult` or `Child` or `Baby` or not.
4. Remember our `Buffer` *class template* from the first stage? Create a `is_buffer` type trait that checks if a given type is a `Buffer`... type??? (is `Buffer` even a type? how can we check if something is created from the `Buffer` *class template*?)
    - Read about [*partial template specializations*](https://en.cppreference.com/w/cpp/language/partial_specialization.html), it might help you!

> [!NOTE]
> In this stage (same as the previous), you are **not** allowed to use c++20 features (concepts, constraints, `requires`).
> As a general broader note, there are many ways to solve the same problem, in c++ and maybe in life in general. In this bootcamp, try to solve the problem using the reading material, as the stages are meant to teach you specific knowledge in a specific order.
