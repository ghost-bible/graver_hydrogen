#pragma once

#include <string>

/**
 * @brief 一个测试类
 */
class Person {
public:
    Person() = default;
    Person(int age, std::string &&name);
    ~Person() = default;

    std::string sayHello();

    inline void age(int age) {
        this->m_age = age;
    }
    inline int age() const {
        return this->m_age;
    }

    inline void name(std::string &&name) {
        this->m_name = std::move(name);
    }
    inline std::string name() {
        return this->m_name;
    }

private:
    int         m_age{0};
    std::string m_name;
};