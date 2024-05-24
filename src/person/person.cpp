#include "graver/person/person.h"

Person::Person(int age, std::string &&name) : m_age(age), m_name(std::move(name)) {}

std::string Person::sayHello() {
    return "Hello World";
}