
// Animal.cpp
#include "Animal.h"
void Lion::makeSound() {
    cout << "Roar!" << endl;
}
void Elephant::makeSound() {
    cout << "Trumpet!" << endl;
}
void Monkey::makeSound() {
    cout << "Ooh ooh aah aah!" << endl;
}
void Bird::makeSound() {
    cout << "Chirp!" << endl;
}
void hearSound(Animal &animal) {
    animal.makeSound();
}

