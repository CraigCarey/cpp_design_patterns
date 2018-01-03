#pragma once

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
protected:
    Person& person;
public:
    PersonBuilderBase(Person &person);

    operator Person() const {
        return std::move(person);
    }

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
public:
    PersonBuilder();

private:
    // Construct the object once rather than for every inherit
    Person p;
};
