//
// Created by pravl on 07.02.2024.
//

#ifndef PARROT_H
#define PARROT_H

#include "../Animal.h"
#include <string>
#include <utility>

class Animal;

class Parrot final : public Animal {
public:
    explicit Parrot (const int &age = 0, const std::string &name = "unknown", Owner* owner = nullptr,
        std::string breed = "unknown") : Animal ("Parrot", age, name, owner), _breed(std::move(breed)) {}

    Parrot (Parrot && other) noexcept : Animal(std::move(other)), _breed(std::move(other._breed)),
        _color(std::move(other._color)) {}

    Parrot& operator=(Parrot && other) noexcept {
        if (this != &other) {
            Animal::operator=(std::move(other));
            _breed = std::move(other._breed);
            _color = std::move(other._color);
        }
        return *this;
    }

    void MakeSound() const override;
    std::string GetBreed ();
    std::string GetColor ();

private:
    std::string _breed;
    std::string _color;
};



#endif //PARROT_H
