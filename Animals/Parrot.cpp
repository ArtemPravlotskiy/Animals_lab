//
// Created by pravl on 07.02.2024.
//

#include <iostream>
#include "Parrot.h"

void Parrot::MakeSound() const {
    std::cout << "Squawk" << std::endl;
}

std::string Parrot::GetBreed() {
    return _breed;
}

std::string Parrot::GetColor() {
    return _color;
}