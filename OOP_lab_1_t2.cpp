#include <iostream>
#include <string>
#include <vector>

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
    int age;
    Dog pet;

    void introduce() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "My dog's name is " << pet.name << endl;
        cout << "Breed: " << pet.breed << endl;
        cout << "Age: " << pet.dog_age << endl;
        pet.bark();
    }
};

class House {
private:
    vector<Person> residents;

public:
    void addPerson(const Person &person) {
        residents.push_back(person);
    }

    void displayResidents() {
        cout << "Residents of the house:" << endl;
        for (auto &resident : residents) {
            resident.introduce();
            cout << endl;
        }
    }
};

int main() {
    House myHouse;
    
    Person person1;
    person1.name = "Alice";
    person1.age = 20;
    person1.pet.name = "Buddy";
    person1.pet.breed = "Labrador";
    person1.pet.dog_age = 3;

    Person person2;
    person2.name = "Bob";
    person2.age = 15;
    person2.pet.name = "Max";
    person2.pet.breed = "Bulldog";
    person2.pet.dog_age = 2;

    Person person3;
    person3.name = "Jake";
    person3.age = 10;
    person3.pet.name = "Goldie";
    person3.pet.breed = "Golden Retriever";
    person3.pet.dog_age = 2;

    myHouse.addPerson(person1);
    myHouse.addPerson(person2);
    myHouse.addPerson(person3);

    myHouse.displayResidents();

    return 0;
}
