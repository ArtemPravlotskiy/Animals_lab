//
// Created by pravl on 07.02.2024.
//

#ifndef CAT_H
#define CAT_H

#include "../Animal.h"
#include <string>
#include <utility>

class Animal;

class Cat final : public Animal {
public:
    explicit Cat (const int &age = 0, const std::string &name = "unknown", Owner* owner = nullptr,
        std::string breed = "unknown") : Animal ("Cat", age, name, owner), _breed(std::move(breed)) {}

    Cat (Cat && other) noexcept : Animal(std::move(other)), _breed(std::move(other._breed)),
            _color(std::move(other._color)) {}

    Cat& operator=(Cat && other) noexcept {
        if (this != &other) {
            Animal::operator=(std::move(other));
            _breed = std::move(other._breed);
            _color = std::move(other._color);
        }
        return *this;
    }

    void MakeSound () const override;
    std::string GetBreed ();
    std::string GetColor ();

private:
    std::string _breed;
    std::string _color;
};



#endif //CAT_H
