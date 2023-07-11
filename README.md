# rmix

c++ agnostic API base with a focus on composition

this API makes use of C++ template mixins and CRTP

## purpose

Provide a consistent composition base for C++ new API's.

## inspiration

Support firmware development and face multiple combination of devices and specs.
Make functionality modular.

Because functionality combinations and devices (mcu's, input and input) combinations are often broaden.

A particular area of interest for this are ilumination control devices, the same functionality can be made available from small 8 bit devices ranging to 32 bit devices with wi-fi, with a variety of inputs encoders, radio, web, etc...  

Often with varying number of channels and control modes.

This is however a broader question on C++ development in general.

## requirements

Because we're aiming tiny devices this library is type defined making possible to define devices as good as hand-writen.

The same level can be achieved with C #define's, however we take advantage of modern C++ syntax type-checking and encapsulation.

## example

define a new API using the `Parts` templates
```c++
template<typename... OO> using MachineDef=Parts<OO...,MyAPI>;
```
 or

```c++
template<typename... OO> using MachineDef=Parts<OO...,MyAPI<Nil>>;
```

**build a final type to adress a particular hardware combination**
```c++
//a shortcut for machine axis definition (using step|dir pins)
template<char name,int dirPin, int stepPin>
using AxisPins=Chain<
  Axis<name>,
  DirPin<dirPin>,
  StepPin<stepPin>
>;

using CNC=MachineDef<
  FeedOvr,
  Accel,
  Feed,
  Len,
  EnablePin<xEnPin>,
  AxisPins<'X',xDirPin,xStepPin>,
  AxisPins<'Y',yDirPin,yStepPin>,
  AxisPins<'Z',zDirPin,zStepPin>
>;
CNC cnc;

```

## about

Typelevel composition abstraction.