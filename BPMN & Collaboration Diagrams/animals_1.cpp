#include <iostream>
#include <vector>
using namespace std;

class Animal {
protected:
    string name;
    int age;
    string species;

public:
    Animal(string n, int a, string s) : name(n), age(a), species(s) {}

    virtual void makeSound() = 0;
    virtual void info() = 0;
    virtual ~Animal() {}
};

class Mammal : public Animal {
public:
    Mammal(string n, int a, string s) : Animal(n, a, s) {}

    void info() override {
        cout << "Mammal - " << species << ", Name: " << name << ", Age: " << age << endl;
    }
};

class Bird : public Animal {
public:
    Bird(string n, int a, string s) : Animal(n, a, s) {}

    void info() override {
        cout << "Bird - " << species << ", Name: " << name << ", Age: " << age << endl;
    }
};

class Reptile : public Animal {
public:
    Reptile(string n, int a, string s) : Animal(n, a, s) {}

    void info() override {
        cout << "Reptile - " << species << ", Name: " << name << ", Age: " << age << endl;
    }
};

class Lion : public Mammal {
public:
    Lion(string n, int a) : Mammal(n, a, "Lion") {}

    void makeSound() override {
        cout << "Roarrr!" << endl;
    }
};

class Eagle : public Bird {
public:
    Eagle(string n, int a) : Bird(n, a, "Eagle") {}

    void makeSound() override {
        cout << "Screeeeech!" << endl;
    }
};

class Snake : public Reptile {
public:
    Snake(string n, int a) : Reptile(n, a, "Snake") {}

    void makeSound() override {
        cout << "Hisssss!" << endl;
    }
};

class Zoo {
private:
    vector<Animal*> animals;

public:
    void addAnimal(Animal* a) {
        animals.push_back(a);
    }

    void showAllAnimals() {
        cout << "\n--- Zoo Animal List ---\n";
        for (Animal* a : animals) {
            a->info();
            a->makeSound();
        }
    }

    ~Zoo() {
        for (Animal* a : animals)
            delete a;
    }
};

int main() {
    Zoo zoo;

    zoo.addAnimal(new Lion("Simba", 5));
    zoo.addAnimal(new Eagle("Sky", 3));
    zoo.addAnimal(new Snake("Slither", 2));

    zoo.showAllAnimals();

    return 0;
}
