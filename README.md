# rmix

c++ agnostic API base with a focus on composition

this API makes use of C++ template mixins and CRTP

## purpose

Provide a consistent composition base for C++ new API's.

## example

```c++
template<typename... OO> using MachineDef=Parts<OO...,MyAPI>;
```
 or

```c++
template<typename... OO> using MachineDef=Parts<OO...,MyAPI<Nil>>;
```

## about

Typelevel composition abstraction.