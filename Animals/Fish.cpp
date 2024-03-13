//
// Created by pravl on 07.02.2024.
//

#include <iostream>
#include "Fish.h"

void Fish::MakeSound() const {
    std::cout << "Blub =)" << std::endl;
}

std::string Fish::GetBreed() {
    return _breed;
}

std::string Fish::GetColor() {
    return _color;
}