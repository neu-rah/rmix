#pragma once
/*
working with mixins and CRTP

our objects will be of this type

struct X {
  templte<typename O>
  struct Part:O {...};
};

where X can have template parameters
*/

/// @brief join multiple part components with the default item API fallback to form a menu item
/// @tparam O the first component type
/// @tparam ...OO optional component types
/// @{
template<typename O,typename... OO>
struct Parts:O::template Part<Parts<OO...>> {
  using Base=typename O::template Part<Parts<OO...>>;
  using Base::Base;
};
template<typename O> struct Parts<O>:O {using O::O;};
/// @}

/// @brief join multiple component parts into a single component part
/// @tparam ...OO optional parts
template<typename... OO> struct Chain 
  {template<typename O> using Part=Parts<OO...,O>;};

/// @brief implement CRTP
/// @details allow open chain derivation to pack components as an unifyed object
/// @tparam T the top level object type so that we can circle-back
template<typename T>
struct Obj {
  using Type=T;
  inline Type& obj() {return *(Type*)this;}
  inline const Type& obj() const {return *(Type*)this;}
  template<typename O> Type& thisObj(O& o) {return obj();}
  template<typename O> const Type& thisObj(const O& o) const {return obj();}
};

template<typename... OO> using Def=Parts<OO...,Still<Nil>>;

//so that we can define a new API like this:
//template<typename... OO> using MachineDef=Def<OO...>;