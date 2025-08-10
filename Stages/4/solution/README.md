
## `is_buffer` and Partial Specializations

In this task we're asked to identify a type, but is it really a type...?

We know from stage 1 that a *class tepmlate* is *not* a type in c++. After instantiation we can a lot of different types, but the *class template* itself is not a type...

What we *do* want to check here is if a certain type can *get instantiated* from a *class template*.

We do that by using the compiler's abilities to "fill in the blanks".

### Declaring Partial Specializations

First of all, we create the *primary class template*, which is a false type. The default case in which the type we've received is not an instantiation (couldn't be created) from the `Buffer` *class tepmlate*.

```c++
template<typename>
struct is_buffer : public std::false_type {};
```

Our primary template accepts a type (which we do our checks on), and inherits `std::false_type` to have a `static constexpr bool value = false`.

After that, we have to create the specialization in which the received `typename` *is some* instantiation of `Buffer`.

In this case, full template specializations don't help us at all - we can't explicitly declare all the different types that can be instantiated from the `Buffer` *class template*.

In this case we use a *partial template specialization*.

*partial template specialization* lets us create a "partially specialized" specialization, "customizing the template code for a given set of template arguments", but only partially, meaning that the "given set of template arguments" can *also be template parameters*.

This is confusing, so let's go over the examples presented at "cppreference":

```c++
template<class T1, class T2, int I>
class A {};             // primary template
```

Here we have the primary template. Meaning that in the end, each specialization of `A` has to end with 2 `class` types and one `int` type.

> [!NOTE]
> In the case of type tepmlate parameters, `class` and `typename` are interchangable.
> If you're curious, the *only* case in which you *have* to use `class` is with *template template parameters*, a quite complex complex we will only get to in advance stages. Keep working hard to get there!

```c++
template<class T, int I>
class A<T, T*, I> {};   // #1: partial specialization where T2 is a pointer to T1
```

Let's go over the syntax:

first of all we declare the template parameters we will in our specialization. We can choose and use any list of parameters we'd like, *as long as we would comply to the primary template* - This is important.

After that, like we did in the full specialization, we tell the compiler which primary template we're about to specialize (`class A`)

Then comes the "trick" - the template argument list. We have to write the argument list for the primary template. Since this should comply to the primary template's parameter list, in our exapmle, it has to be - `class`, `class`, `int`.

As we can observe from the example, the argument list is `T, T*, I` (which is `class`, `class`, `int`).

In other words, we used a different parameter list, with a different amount of parameters, to specialize the primary template. 

There are a great amount of specializations we can create this way:

```c++
template<class T, class T2, int I>
class A<T*, T2, I> {};  // #2: partial specialization where T1 is a pointer

template<class T>
class A<int, T*, 5> {}; // #3: partial specialization where
                        //     T1 is int, I is 5, and T2 is a pointer

template<class X, class T, int I>
class A<X, T*, I> {};   // #4: partial specialization where T2 is a pointer
```

- Cases 2 and 4 has the same parameter list as in the primary template, but they're being used differently in the argument list.
- In Case 3 the specialization's parameter list only has one *type template parameter* and a literal `5` value used as the `int` parameter.

> [!NOTE]
> In the example above no implementation has been written, but in real-life scenarios an implementation would have been written.

### Using the Parital Specializations

Continuing with the example above, the partial specializations would come into use when filling the *template arguments* of the **primary tempalte**.

The same with full specializations, we fill the arguments for the primary template (in this case, we would have to give: `class`, `class`, `int`)

Only then, the compiler will try to see if the arguments we've instantiated the template with fit into a more specialized case.

From "cppreference":

> When a class or variable(since C++14) template is instantiated, and there are partial specializations available, the compiler has to decide if the primary template is going to be used or one of its partial specializations.

> [!NOTE]
> The compiler always prefers to take the most "specialized" (the most fitting) specialization.
> From "cppreference":
> "Informally 'A is more specialized than B' means 'A accepts a subset of the types that B accepts'."

```c++
// given the template A as defined above
A<int, int, 1> a1;      // no specializations match, uses primary template
A<int, int*, 1> a2;     // uses partial specialization #1 (T = int, I = 1)
A<int, char*, 5> a3;    // uses partial specialization #3, (T = char)
A<int, char*, 1> a4;    // uses partial specialization #4, (X = int, T = char, I = 1)
A<int*, int*, 2> a5;    // error: matches #2 (T = int, T2 = int*, I= 2)
                        //        matches #4 (X = int*, T = int, I = 2)
                        // neither one is more specialized than the other
```

- `a2` fits to the first specialization because `T1` and `T2` has the same type while `T2` being a pointer to that type (which is a type in itself and so fits the primary template).
- `a3` fits #3 specialization:
    - first type is `int`
    - second type is a pointer type (no matter to what type, as long as it's a pointer. It can even be a pointer to a pointer!)
    - Third type is a literal `5` value (an `int` value)
- `a4` fits the #4 specialization with the same logic of `a2`.

`a5` is an interesting case in which the compiler will result in an error:

```
./partial_specialization.cpp: In function ‘int main()’:
./partial_specialization.cpp:23:22: error: ambiguous template instantiation for ‘class A<int*, int*, 2>’
   23 |     A<int*, int*, 2> a5; // error: matches #2 (T = int, T2 = int*, I= 2)
      |                      ^~
./partial_specialization.cpp:8:7: note: candidates are: ‘template<class T, class T2, int I> class A<T*, T2, I> [with T = int; T2 = int*; int I = 2]’
    8 | class A<T*, T2, I> {};  // #2: partial specialization where T1 is a pointer
      |       ^~~~~~~~~~~~
./partial_specialization.cpp:15:7: note:                 ‘template<class X, class T, int I> class A<X, T*, I> [with X = int*; T = int; int I = 2]’
   15 | class A<X, T*, I> {};   // #4: partial specialization where T2 is a pointer
      |       ^~~~~~~~~~~
./partial_specialization.cpp:23:22: error: aggregate ‘A<int*, int*, 2> a5’ has incomplete type and cannot be defined
   23 |     A<int*, int*, 2> a5; // error: matches #2 (T = int, T2 = int*, I= 2)
      |                      ^~
```

Neither specialiation #2 or specialziation #4 is more specialized than the other (`T1` is a pointer type but `T2` is also a pointer type), so the compiler can't decide between them.

Notice, however, that if we had a `template<class X, class T, int I> class A<X*, T*, I>` specialization our program would be able to compile. Since this specialization is more specialized case than both #2 and #4, the compiler would just choose it for `a5`.

### Implementing `is_buffer`

