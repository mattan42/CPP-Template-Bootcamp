# Stage 2.5 - Using Constraints, Concepts and requirements.

"Constraints" and "Concepts" are relativevly new c++ features added in c++20.

They managed to become a part of the c++ standard to solve the exact set of problems presented in stage 2.

In stage 2 we introduced the "manual" way to enforce a set of requirements on a type. In our `max` function template case, we forced the *type template parameter* to have a copy/move constructor and to be an integral type using `static_assert`s and the `type_traits` library.

However, the solution to the problem of the previous stage is not the only solution available, let alone the only problem present - "SFINAE" is another method we use to address problems of the same set (you'll learn about that in later stages).

"Constraints" and "Concepts" entered the standard to give a more clear and "built-in" solution for this set of problems.

In this stage we'll implement the same solution as the previous using only c++20 features, in order to start getting ourselves familiar with c++20's "Constraints" and "Concepts".

## Objective

1. Briefly look at the following pages (from cppreference):
    - [Constraints and concepts](https://en.cppreference.com/w/cpp/language/constraints.html)
    - [`requires` expression](http://en.cppreference.com/w/cpp/language/requires.html)
    - [Concepts library](https://en.cppreference.com/w/cpp/concepts.html)

> [!INFO]
> You don't have to read them entirely of course - try to grasp the general idea of how to work with concepts and return to these documentation pages as a part of your trial and error process.

2. Implement the objectives of the previous stage, this time using *only* c++20 features.

> [!INFO]
> More specifically, you are **not allowed** to include the `type_traits` library.
