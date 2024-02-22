
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() = 0; 
};

class Lion : public Animal {
public:
    void makeSound() override {
        cout << "Roar!" << endl;
    }
};

class Elephant : public Animal {
public:
    void makeSound() override {
        cout << "Trumpet!" << endl;
    }
};

class Monkey : public Animal {
public:
    void makeSound() override {
        cout << "Ooh ooh aah aah!" << endl;
    }
};

class Bird : public Animal {
public:
    void makeSound() override {
        cout << "Chirp!" << endl;
    }
};
void hearSound(Animal &animal) {
    animal.makeSound();
}
int main() {
    Lion lion;
    Elephant elephant;
    Monkey monkey;
    Bird bird;
    hearSound(lion);
    hearSound(elephant);
    hearSound(monkey);
    hearSound(bird);
    return 0;
}
