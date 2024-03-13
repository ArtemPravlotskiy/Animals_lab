//
// Created by pravl on 07.02.2024.
//

#include "Owner.h"
#include <cstdint>
#include <unordered_set>
#include "Animal.h"

Owner::~Owner() {
    for (const auto pet : _pets) {
        delete pet;
    }
}

std::string Owner::GetName() const {
    return _name;
}

std::string Owner::GetAdress() const {
    return _adress;
}

void Owner::ChangeAdress(const std::string &adress) {
    _adress = adress;
}


void Owner::AddPet(Animal *newPet) {
    _pets.emplace_back(newPet);
}

int Owner::GetNumberOfPets() const {
    return static_cast<int32_t>(_pets.size());
}

int Owner::NumberOfSpecies() const {
    std::unordered_set <std::string> species;
    for (const auto pet : _pets) {
        species.insert(pet->GetSpecie());
    }
    return static_cast<int32_t>(species.size());
}

std::vector<Animal *> Owner::GetPets() const {
    return _pets;
}


