//
// Created by pravl on 12.03.2024.
//
#ifndef CLASSICFACTORY_H
#define CLASSICFACTORY_H


#include "Animal.h"
#include "Animals/Cat.h"
#include "Animals/Dog.h"
#include "Animals/Fish.h"
#include "Animals/Parrot.h"


class AnimalFactory {
  public:
    [[nodiscard]] virtual Animal *createAnimal(int age, std::string pet_name, Owner *owner) const = 0;

    virtual ~AnimalFactory() = default;
};

class CatFactory final : public AnimalFactory {
  public:
    [[nodiscard]] Animal* createAnimal(const int age, const std::string pet_name, Owner *owner) const override {
        return new Cat(age, pet_name, owner);
    }
};

class DogFactory final : public AnimalFactory {
public:
    [[nodiscard]] Animal* createAnimal(const int age, const std::string pet_name, Owner *owner) const override {
        return new Dog(age, pet_name, owner);
    }
};

class FishFactory final : public AnimalFactory {
public:
    [[nodiscard]] Animal* createAnimal(const int age, const std::string pet_name, Owner *owner) const override {
        return new Fish(age, pet_name, owner);
    }
};

class ParrotFactory final : public AnimalFactory {
public:
    [[nodiscard]] Animal* createAnimal(const int age, const std::string pet_name, Owner *owner) const override {
        return new Parrot(age, pet_name, owner);
    }
};


#endif //CLASSICFACTORY_H
