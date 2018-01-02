# Design Patterns in Modern CPP

Based on [Dmitri Nesteruk's Udemy course](https://www.udemy.com/patterns-cplusplus)

## SOLID Principles
### S - Single Responsibility
A Class should have a single reason to change

It should have a primary responsibility and not take on other responsibilities
### O - Open Closed
Systems should be open to extension, but closed to modification
### L - Liskov Substitution
Subtypes should be immediately substitutable for their basetypes

i.e. if a square inherits from rectangle, it should be useable wherever a rectangle can be used
### I - Interface Segregation
Keep interface sizes small and maintainable

Don't be tempted to put all operations into a single interface
