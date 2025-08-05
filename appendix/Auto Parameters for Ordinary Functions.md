# Auto Parameters for Ordinary Functions

c++20 provides an even "cleaner" and simpler solution for stage 1's `max` *function template*:

```c++
auto max(auto v1, auto v2)
{
    return v1 < v2 ? v2 : v1;
}
```

This solution can be used thanks to a c++20 feature that allows `auto` to be used on parameters of "ordinary functions".

However, notice that this solution is *equivelant* to the *function template* solution presented in the solution of stage 1, except that:
- `T` is not available.
- There can be actually two `typename` template parameters, depends on what is given to the function as `v1` and `v2`.
- We don't know which type will be returned and will probably have to use `decltype` or some kind of type query on the returned value in some way or another.

In this solution, the same as with tempaltes, the compiler will create an instantiation for the types of arguments used when calling this function.
