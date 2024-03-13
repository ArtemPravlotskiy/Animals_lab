//
// Created by pravl on 07.02.2024.
//

#include "Animal.h"

#include <cassert>

#include "Owner.h"
#include "Animals/Cat.h"
#include "Animals/Dog.h"
#include "Animals/Fish.h"
#include "Animals/Parrot.h"

/*Animal::~Animal()  {
    delete _owner;
}*/

std::string Animal::GetSpecie () const {
    return _specie;
}

std::string Animal::GetName () const {
    return _name;
}

int Animal::GetAge () const {
    return _age;
}

bool Animal::IsHomeless () const {
    return _owner == nullptr;
}

int Animal::GetID() const {
    return ID;
}

Owner * Animal::GetOwner() const {
    return _owner;
}

Animal * Animal::createAnimal(const Animal_ID id, const int age, const std::string &pet_name, Owner *owner) {
    switch (id) {
        case Cat_ID:
            return new Cat(age, pet_name, owner);
        case Dog_ID:
            return new Dog(age, pet_name, owner);
        case Parrot_ID:
            return new Parrot(age, pet_name, owner);
        case Fish_ID:
            return new Fish(age, pet_name, owner);
        default:
            assert(false);
    }
}

int Animal::GetNewID() {
    static int lastID = 111111111; // Локальная статическая переменная
    return lastID++;
}

/*void Animal::GetInfo () {

}*/
