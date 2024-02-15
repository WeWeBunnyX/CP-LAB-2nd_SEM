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
    int age;
    Dog pet; //From Dog class

    void introduce() {
        cout << "Person's name: " << name << endl;
        cout << "Person's age: " << age << endl;
        cout << "Dog's name: " << pet.name << endl;
        cout << "Dog's breed: " << pet.breed << endl;
        cout << "Dog's age: " << pet.dog_age << endl;
    }
};

class House {
private:
    Person owner;

public:
    void Owner(Person &person) {
        owner = person;
    }

    void displayDetails() {
        cout << "House details:" << endl;
        owner.introduce();
    }
};

int main() {
    Person person;
    person.name = "Alice";
    person.age = 30;

    Dog dog;
    dog.name = "Buddy";
    dog.breed = "Labrador";
    dog.dog_age = 3;

    person.pet = dog;

    House myHouse;
    
    myHouse.Owner(person);

    myHouse.displayDetails();

    return 0;
}
