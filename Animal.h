//
// Created by pravl on 07.02.2024.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <utility>

class Owner;

enum Animal_ID { Cat_ID = 0, Dog_ID, Fish_ID, Parrot_ID};

class Animal {
public:
    Animal (std::string specie, const int &age, std::string name, Owner *owner):
         _specie(std::move( specie)), _age(age), _name(std::move(name)), _owner(owner), ID(GetNewID()) {}

    Animal (Animal && other) noexcept : _specie(std::move(other._specie)), _age(other._age),
    _name(std::move(other._name)), _owner(other._owner), ID(other.ID) {
        other._owner = nullptr;
    }

    Animal& operator=(Animal && other) noexcept {
        if (this != &other) {
            _specie = std::move(other._specie);
            _age = other._age;
            _name = std::move(other._name);
            _owner = other._owner;
            ID = other.ID;

            other._owner = nullptr;
        }
        return *this;
    }

    //virtual ~Animal ();

    [[nodiscard]] std::string GetSpecie () const;
    [[nodiscard]] std::string GetName () const;
    [[nodiscard]] int GetAge () const;
    [[nodiscard]] bool IsHomeless () const;
    [[nodiscard]] int GetID () const;
    [[nodiscard]] Owner* GetOwner () const;
    // void GetInfo ();
    virtual void MakeSound () const = 0;


    static Animal* createAnimal (Animal_ID id, int age, const std::string &pet_name, Owner* owner);


private:
    std::string _specie;
    int _age;
    std::string _name;
    Owner* _owner;
    int ID;

    static int GetNewID();
};


#endif //ANIMAL_H
