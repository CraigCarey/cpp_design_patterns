# Design Patterns in Modern CPP

Based on [Dmitri Nesteruk's Udemy course](https://www.udemy.com/patterns-cplusplus)

## SOLID Principles

### S - Single Responsibility
A Class should have a single reason to change

It should have a primary responsibility and not take on other responsibilities

**_Separation of concerns_** - different classes handling different, independent tasks/problems

### O - Open Closed
Systems should be open to extension, but closed to modification

To extend functionality use inheritance rather than modifying existing code

### L - Liskov Substitution
Subtypes should be immediately substitutable for their basetypes

i.e. if a square inherits from rectangle, it should be useable wherever a rectangle can be used

### I - Interface Segregation
Keep interface sizes small and maintainable

Don't be tempted to put all operations into a single interface

*YAGNI* - You ain't gonna need it

### D - Dependency Inversion
Specifies the best way to form dependencies between objects

1. High-level modules should not depend on low-level modules

   Both should depend on abstractions (interfaces)
   This makes it easy to change the underlying implementation
2. Abstractions should not depend on details
  
   Details should depend on abstractions


## Other Patterns

### Builder
When piecewise object construction is complicated, provide an API for doing it succinctly

A builder is a separate component for building an object

Can either give builder a constructor or return it via a static function

To make a builder fluid retutn *this*

Different facets of an object can ve built with different builders working in tandem via a base class
