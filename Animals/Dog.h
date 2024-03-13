//
// Created by pravl on 07.02.2024.
//

#ifndef DOG_H
#define DOG_H

#include "../Animal.h"
#include <string>
#include <utility>

class Animal;

class Dog final : public Animal {
public:
    explicit Dog (const int &age = 0, const std::string &name = "unknown", Owner* owner = nullptr,
        std::string breed = "unknown") : Animal ("Dog", age, name, owner), _breed(std::move(breed)) {}

    Dog (Dog && other) noexcept : Animal(std::move(other)), _breed(std::move(other._breed)),
        _color(std::move(other._color)) {}

    Dog& operator=(Dog && other) noexcept {
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



#endif //DOG_H
