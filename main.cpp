#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Animal.h"
#include "Owner.h"
#include "Animals/Cat.h"
#include "Animals/Dog.h"
#include "Animals/Fish.h"
#include "Animals/Parrot.h"
#include "ClassicFactory.h"
#include "Factory.h"

using namespace std;

vector<Owner*> owners;
/*vector<Animal*> animals;*/
CompositeAnimal* animalss = new CompositeAnimal;

void Input();
void StartMenu();
Animal* FindByID(const int &ID);

auto cat_factory = new CatFactory;
auto dog_factory = new DogFactory;
auto parrot_factory = new ParrotFactory;
auto fish_factory = new FishFactory;

void Delete();

int main() {




    // std::move test
    /*Owner artem{"artem"};
    Cat cat{5, "Artem", &artem, ""};
    Cat cat1 = std::move(cat);

    int k = 6;*/

    //main part of programm
    Input();
    cout << "Successful data entry" << endl;
    system("pause");
    cout << "\n";
    StartMenu();
    cout << "exit...";
    Delete();

    return 0;
}

void Split(const string &line, vector <string> &words) {
    for (int l = 0, r = 1; r <= line.length(); r++) {
        if (line[r] == ',' || r == line.length()) {
            words.emplace_back(line.substr(l, r - l));
            l = r + 2;
            r = l - 1;
        }
    }
}

void Input () {
    ifstream fin ("../input.txt");
    if (!fin.is_open()) {
        throw std::ifstream::failure("Failed to open input file");
    }

    string line;
    while (getline(fin, line)) {

        // Input line
        string owner_name, specie, pet_name, age;
        vector <string> words;
        Split(line, words);

        try {
            if (words[0].empty()) {
                throw string("Empty owner name");
            }
            if (words[1].empty()) {
                throw string("Empty specie");
            }
            if (words[3].empty()) {
                throw string("Empty age");
            }
            if (words[2].empty() && words[1] != "Fish") {
                throw string("Empty pet name");
            }

        } catch (string& error) {
            cout << error << endl;
        }

        owner_name = words[0];
        specie =words[1];
        pet_name = words[2];
        age = words[3];



        // Input processing

        // try to find owner
        auto it_owner = ranges::find_if(owners,
                                        [&owner_name](const auto& owner) {
                                            return owner->GetName() == owner_name;
                                        });

        // if owner is not find, so create new owner
        if (it_owner == owners.end()) {
            owners.emplace_back ( new Owner(owner_name) );
            it_owner = --owners.end();
        }


        try {
            //not Factory pattern
            /*if (specie == "Cat") {
                animals.emplace_back(new Cat(stoi(age), pet_name, *it_owner));
            } else if (specie == "Dog") {
                animals.emplace_back(new Dog(stoi(age), pet_name, *it_owner));
            } else if (specie == "Fish") {
                animals.emplace_back(new Fish(stoi(age), pet_name, *it_owner));
            } else if (specie == "Parrot") {
                animals.emplace_back(new Parrot(stoi(age), pet_name, *it_owner));
            } else {
                throw string("Unknown specie");
            }*/

            // Classic factory
            /*if (specie == "Cat") {
                animals.emplace_back(cat_factory->createAnimal(stoi(age), pet_name, *it_owner));
            } else if (specie == "Dog") {
                animals.emplace_back(dog_factory->createAnimal(stoi(age), pet_name, *it_owner));
            } else if (specie == "Fish") {
                animals.emplace_back(fish_factory->createAnimal(stoi(age), pet_name, *it_owner));
            } else if (specie == "Parrot") {
                animals.emplace_back(parrot_factory->createAnimal(stoi(age), pet_name, *it_owner));
            } else {
                throw string("Unknown specie");
            }*/

            // factory
            /*if (specie == "Cat") {
                animals.emplace_back(Animal::createAnimal(Cat_ID, stoi(age), pet_name, *it_owner));
            } else if (specie == "Dog") {
                animals.emplace_back(Animal::createAnimal(Dog_ID, stoi(age), pet_name, *it_owner));
            } else if (specie == "Fish") {
                animals.emplace_back(Animal::createAnimal(Fish_ID, stoi(age), pet_name, *it_owner));
            } else if (specie == "Parrot") {
                animals.emplace_back(Animal::createAnimal(Parrot_ID, stoi(age), pet_name, *it_owner));
            } else {
                throw string("Unknown specie");
            }*/

            // my Factory
            /*if (specie == "Cat") {
                animals.emplace_back(Factory::create_t<Cat>(stoi(age), pet_name, *it_owner));
            } else if (specie == "Dog") {
                animals.emplace_back(Factory::create_t<Dog>( stoi(age), pet_name, *it_owner));
            } else if (specie == "Fish") {
                animals.emplace_back(Factory::create_t<Fish>( stoi(age), pet_name, *it_owner));
            } else if (specie == "Parrot") {
                animals.emplace_back(Factory::create_t<Parrot>( stoi(age), pet_name, *it_owner));
            } else {
                throw string("Unknown specie");
            }

            (*it_owner)->AddPet(animals.back());*/

            if (specie == "Cat") {
                animalss->addAnimal(Factory::create_t<Cat>(stoi(age), pet_name, *it_owner));
            } else if (specie == "Dog") {
                animalss->addAnimal(Factory::create_t<Dog>( stoi(age), pet_name, *it_owner));
            } else if (specie == "Fish") {
                animalss->addAnimal(Factory::create_t<Fish>( stoi(age), pet_name, *it_owner));
            } else if (specie == "Parrot") {
                animalss->addAnimal(Factory::create_t<Parrot>( stoi(age), pet_name, *it_owner));
            } else {
                throw string("Unknown specie");
            }

            (*it_owner)->AddPet(animalss->back());

        } catch (string& error) {
            cout << "\nError: " << error << endl;
        }
    }
}

void CountAnimalTypesPerOwner(const vector<Owner*>& owners) {
    unordered_map<string, int> animal_counts;
    for (const auto& owner : owners) {
        animal_counts[owner->GetName()] = owner->NumberOfSpecies();
    }

    for (const auto& [owner_name, count] : animal_counts) {
        cout << "Owner: " << owner_name << ", Number of animal types: " << count << endl;
    }
}

void PrintOwnersAndPetsBySpecies(const vector<Owner*>& owners, const string& species) {
    struct AnimalInfo {
        string owner_name;
        string pet_name;

        bool operator==(const AnimalInfo& other) const {
            return owner_name == other.owner_name && pet_name == other.pet_name;
        }
    };

    vector<AnimalInfo> animals_info;

    for (const auto& owner : owners) {
        for (const auto& pet : owner->GetPets()) {
            if (pet->GetSpecie() == species) {
                animals_info.push_back({owner->GetName(),
                    pet->GetName().empty() ? "Fish" : pet->GetName()});
            }
        }
    }

    animals_info.erase(ranges::unique(animals_info).begin(), animals_info.end());

    cout << "Owners and pets of species " << species << ":" << endl;
    for (const auto& info : animals_info) {
        cout << "Owner: " << info.owner_name << ", Pet: " << info.pet_name << endl;
    }
}

void CountSpeciesByPetName(const vector<Owner*>& owners, const string& pet_name) {
    unordered_map<string, int> species_counts;
    for (const auto& owner : owners) {
        for (const auto& pet : owner->GetPets()) {
            if (pet->GetName() == pet_name) {
                species_counts[pet->GetSpecie()]++;
            }
        }
    }

    cout << "Number of species for pet name " << pet_name << ":" << endl;
    for (const auto& [species, count] : species_counts) {
        cout << "Species: " << species << ", Count: " << count << endl;
    }
}

void PrintOldestAndYoungestPerSpecies(const vector<Owner*>& owners) {
    unordered_map<string, pair<int, int>> age_info;
    for (const auto& owner : owners) {
        for (const auto& pet : owner->GetPets()) {
            string species = pet->GetSpecie();
            int age = pet->GetAge();
            if (!age_info.contains(species)) {
                age_info[species] = {age, age};
            } else {
                age_info[species].first = max(age_info[species].first, age);
                age_info[species].second = min(age_info[species].second, age);
            }
        }
    }
    // Выводим результаты
    cout << "Oldest and youngest pets per species:" << endl;
    for (const auto& [species, ages] : age_info) {
        cout << "Species: " << species << ", Oldest: " << ages.first << ", Youngest: " << ages.second << endl;
    }
}

void MakeSound() {
    int choice;
    cout << "1. Cat" << endl;
    cout << "2. Dog" << endl;
    cout << "3. Fish" << endl;
    cout << "4. Parrot" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    const Animal* animal;

    switch (choice) {
        case 1:
            animal = new Cat();
            break;
        case 2:
            animal = new Dog();
            break;
        case 3:
            animal = new Fish();
            break;
        case 4:
            animal = new Parrot();
            break;
        default:
            cout << "Invalid choice" << endl;
            return;
    }

    animal->MakeSound();
    delete animal;
}

void MakeAllPetsSound() {
    cout << "\n";
    auto animals = animalss->getAnimals();
    for (const auto pet : animals) {
        if (!pet->GetName().empty()) {
            cout << pet->GetName() << " ";
        }
        else {
            cout << "Fish ";
        }
        pet->MakeSound();
    }
    cout << "\n";
}

void FindAnimalByID(const int &ID) {
    if (const Animal* pet = FindByID(ID); pet == nullptr) {
        cout << "Pet is not find" << endl;
    } else {
        cout << "Specie: " << pet->GetSpecie() << endl;
        cout << "Pet name: " << pet->GetName() << endl;
        cout << "Age: " << pet->GetAge() << endl;
        cout << "Owner: " << pet->GetOwner()->GetName() << endl;
    }
}

void StartMenu() {
    int choice;
    cout << "1. Count different animal types per owner" << endl;
    cout << "2. Print owners and pets by species" << endl;
    cout << "3. Count species by pet name" << endl;
    cout << "4. Print oldest and youngest pets per species" << endl;
    cout << "5. Make some sound" << endl;
    cout << "6. Make all pets sound" << endl;
    cout << "7. Find animal by ID" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            CountAnimalTypesPerOwner(owners);
            break;
        case 2: {
            string species;
            cout << "Enter species: ";
            cin >> species;
            PrintOwnersAndPetsBySpecies(owners, species);
            break;
        }
        case 3: {
            string pet_name;
            cout << "Enter pet name: ";
            cin >> pet_name;
            CountSpeciesByPetName(owners, pet_name);
            break;
        }
        case 4:
            PrintOldestAndYoungestPerSpecies(owners);
            break;
        case 5:
            MakeSound();
            break;
        case 6:
            MakeAllPetsSound();
            break;
        case 7: {
            int ID;
            cout << "Enter pet ID: ";
            cin >> ID;
            FindAnimalByID(ID);
            break;
        }
        case 8:
            return;
        default:
            cout << "Invalid choice" << endl;
    }
    system("pause");
    cout << "\n\n";
    StartMenu();
}

Animal* FindByID(const int &ID) {
    auto animals = animalss->getAnimals();
    for (const auto animal : animals) {
        if (ID == animal->GetID()) {
            return animal;
        }
    }
    return nullptr;
}

void Delete() {
    /// Factories delete
    delete cat_factory;
    delete dog_factory;
    delete parrot_factory;
    delete fish_factory;

    /// Owners delete
    for (const auto x : owners) {
        delete x;
    }

    /// Animals delete
    /// Owner also delete all of his animal, so we should only clear animals vector
    //animals.clear();
}