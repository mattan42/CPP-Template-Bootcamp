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
