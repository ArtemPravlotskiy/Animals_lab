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
    [[nodiscard]] virtual Animal* createAnimal() const = 0;
    virtual ~AnimalFactory() = default;
};

class CatFactory final : public AnimalFactory {
  public:
    [[nodiscard]] Animal* createAnimal() const override {
        return new Cat;
    }
};

class DogFactory final : public AnimalFactory {
public:
    [[nodiscard]] Animal* createAnimal() const override {
        return new Dog;
    }
};

class FishFactory final : public AnimalFactory {
public:
    [[nodiscard]] Animal* createAnimal() const override {
        return new Fish;
    }
};

class ParrotFactory final : public AnimalFactory {
public:
    [[nodiscard]] Animal* createAnimal() const override {
        return new Parrot;
    }
};


#endif //CLASSICFACTORY_H
