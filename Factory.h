//
// Created by pravl on 12.03.2024.
//

#ifndef FACTORY_H
#define FACTORY_H

#include "Animal.h"

class Factory {
public:
    template <class T>
    static T* create_t(const int age, std::string pet_name, Owner* owner = nullptr) {
        return new T(age, pet_name, owner);
    }
};



#endif //FACTORY_H
