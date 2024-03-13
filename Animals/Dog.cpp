//
// Created by pravl on 07.02.2024.
//

#include <iostream>
#include "Dog.h"

void Dog::MakeSound() const {
    std::cout << "WOOF!!!" << std::endl;
}

std::string Dog::GetBreed() {
    return _breed;
}

std::string Dog::GetColor() {
    return _color;
}