#include <iostream>
#include <string>
using namespace std;

class Dog {
public:
    string name;
    string breed;
    int dog_age;
    
    void bark() {
        cout << name << " says Woof!" << endl;
    }
};

class Person {
public:
    string name;
    Dog pet;

    void introducePet() {
        cout << "My dog's name is " << pet.name << endl;
        cout << "Breed: " << pet.breed << endl;
        cout << "Age: " << pet.dog_age << endl;
        pet.bark();
    }
};

int main() {
    Person person1;
    person1.name = "Alice";
    person1.pet.name = "Buddy";
    person1.pet.breed = "Labrador";
    person1.pet.dog_age = 3;
    
    person1.introducePet();

    return 0;
}
