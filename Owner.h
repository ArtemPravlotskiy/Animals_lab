//
// Created by pravl on 07.02.2024.
//

#ifndef OWNER_H
#define OWNER_H

#include <utility>
#include <vector>
#include <string>

class Animal;

class Owner {
public:
    explicit Owner (std::string name) : _name(std::move(name)) {};
    Owner (Owner && other) noexcept : _name(std::move(other._name)), _adress(std::move(other._adress)), _pets(std::move(other._pets)) {
        other._pets.clear();
    }

    ~Owner();

    Owner& operator=(Owner&& other) noexcept {
        if (this != &other) {
            _name = std::move(other._name);
            _adress = std::move(other._adress);
            _pets = std::move(other._pets);

            other._pets.clear();
        }
        return *this;
    }

    [[nodiscard]] std::string GetName () const;
    [[nodiscard]] std::string GetAdress () const;
    void ChangeAdress (const std::string &adress);
    void AddPet (Animal* newPet);
    [[nodiscard]] int GetNumberOfPets () const;
    [[nodiscard]] int NumberOfSpecies () const;
    [[nodiscard]] std::vector <Animal*> GetPets () const;

private:
    std::string _name;
    std::string _adress;
    std::vector <Animal*> _pets;

};



#endif //OWNER_H
