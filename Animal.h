//
// Created by pravl on 07.02.2024.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <utility>
#include <vector>

class Owner;
class CompositeAnimal;

enum Animal_ID { Cat_ID = 0, Dog_ID, Fish_ID, Parrot_ID};

class Animal {
public:
    Animal() = default;

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

    virtual ~Animal () = default;

    [[nodiscard]] std::string GetSpecie () const;
    [[nodiscard]] std::string GetName () const;
    [[nodiscard]] int GetAge () const;
    [[nodiscard]] bool IsHomeless () const;
    [[nodiscard]] int GetID () const;
    [[nodiscard]] Owner* GetOwner () const;
    // void GetInfo ();
    virtual void MakeSound () const = 0;


    static Animal* createAnimal (Animal_ID id, int age, const std::string &pet_name, Owner* owner);

    virtual CompositeAnimal* getComposite() {
        return nullptr;
    }

private:
    std::string _specie;
    int _age;
    std::string _name;
    Owner* _owner;
    int ID;

    static int GetNewID();
};


class CompositeAnimal final : public Animal {
public:
    //CompositeAnimal() = default;

    void addAnimal(Animal* animal) {
        a.push_back(animal);
    }

    CompositeAnimal* getComposite() override {
        return this;
    }

    ~CompositeAnimal() override {
        for (const auto x : a) {
            delete x;
        }
    }

    void MakeSound() const override {}

    [[nodiscard]] Animal* back() const {
        return a.back();
    }

    [[nodiscard]] std::vector<Animal*> getAnimals() const {
        return a;
    }

private:
    std::vector<Animal*> a;
};



#endif //ANIMAL_H
