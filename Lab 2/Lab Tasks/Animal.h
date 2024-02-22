
// Animal.h
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() = 0;
};

class Lion : public Animal {
public:
    void makeSound() override;
};

class Elephant : public Animal {
public:
    void makeSound() override;
};

class Monkey : public Animal {
public:
    void makeSound() override;
};

class Bird : public Animal {
public:
    void makeSound() override;
};
void hearSound(Animal &animal);
