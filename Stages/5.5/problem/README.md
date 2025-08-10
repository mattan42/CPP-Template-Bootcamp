# Stage 5.5 - Preventing Abuse of `is_human_like`.

> [!NOTE]
> This is a *bonus stage*. It contains extra useful knowledge which was not categorised as "necessary".
> Nontheless, the things discussed at these stages are helpful.

In stage 5 we've created a `is_human_like` type trait that can be a bit abused.

Even though we set the second template parameter to deafult to `void`, a user can still fill this parameter with an argument with it's own, for example:

```c++
is_human_like<Alien, bool>::value // [= false]
```

Even though `Alien` *is* "human like", the type-trait yielded `false`.

Our partial specialization specializes a case in which the second template argument is `void`. Because the user set the second template parameter to be `bool`, our specialization was not even a candidate, and the primary template was chosen.

> [!NOTE]
> Even though the substitution inside the partial specialization was successfull (`Alien` has a public member `int age`), it was not chosen simple because the case of `Alien, bool` is not specialized by this case.


## Objective

Like Bjarne Stroustrup famously said:

> "C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do it blows your whole leg off"

So how can we better prevent such "abuse" and make it harder for the user to blow his whole leg off?

