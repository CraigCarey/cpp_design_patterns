#pragma once

#include <string>
#include <ostream>

class PersonBuilder;

class Person
{
    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;

    // address
    std::string street_address;
    std::string post_code;
    std::string city;

    // employment
    std::string company_name;
    std::string position;
    int annual_income{0};

public:
    static PersonBuilder create();

    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};
