//
// Created by pravl on 07.02.2024.
//

#include <iostream>
#include "Cat.h"

void Cat::MakeSound() const {
    std::cout << "Meeew" << std::endl;
}

std::string Cat::GetBreed() {
    return _breed;
}

std::string Cat::GetColor() {
    return _color;
}