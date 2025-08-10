# Stage 5.5 - Solution

## `static_assert` in Primary Template

The solution is quite straight-forward but elegant.

Let's go over the problem once again: The user tries instantiating `is_human_like` with the second template parameter, not leaving it to be the default option.

This can be one of 2 cases
1. The user set the second template argument to `void`
2. The user set the second tempalte argumet to a type other than `void`.

The first case, even thoguh it's not the prettiest in terms of code readability (and for sure is avoidable by using the defualt template argument) is correct in terms of logic.

The second case, as presented in this stage's question page, will cause the compiler to always choose the primary template, so how about we make srue in the primary template that this template parameter is `void`?

If it is indeed `void`, then it means our logic worked correctly, and the examined type is indeed not "human like" and should've ended up getting instantiated with the implementation of the primary template.

If it is not `void`, then it means the user has tinkered with our template code and inserted himself a second template argument which was not `void`.

Checking if the second template parameter is `void` or not is easy, and uses techniques we've used in the previous stages - `std::is_same` and `static_assert` (which also allows us leaving a nice message explaining what has been done wrong).
