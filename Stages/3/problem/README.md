# Stage 3 - Specializations

In the last stage we've seen a good usage of the `type_traits` library - while we have no choice but accepting a generic type `T` to our function template or class template, we can enfore the compiler to accept only types that answer our critiques.

However, when our code-bases get more and more complex, we might want to have type-checks on types we've developed ourselves. For example, if we have `Adult`, `Child`, `Baby` classes, and we want to accept a `typename HumanType`, we need to have a custom "type_trait" check `is_human<HumanType>`.

This is what we'll do in this stage!

## Objective

1. Read about *template specialization*.
2. Create a `is_human` type trait that accepts a *type template parameter* and checks if the received *type template parameter* is an `Adult` or `Child` or `Baby` or not.
3. The previous type is good if we want to enforce the received type to specifically be `Adult`, `Child` or `Baby`, but what if we want to be able to receive a `HumanLike`?
    - Create a `is_human_like` type trait that accepts a *type template parameter* and checks if the received type has a public member `int age` **and** a public method `void think()` (if the type has just one or none - then it's not "human like").
4. Create a *class template* 