#include 
#include 
#include 
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

class House {
public:
    vector persons;

    void addPerson(const Person& newPerson) {
        persons.push_back(newPerson);
    }

    void displayPersonsDetails() {
        for (const auto& person : persons) {
            cout << "Name: " << person.name << endl;
            person.introducePet();
            cout << endl;
        }
    }
};

int main() {
    House myHouse;
    
    Person person1;
    person1.name = "Alice";
    person1.pet.name = "Buddy";
    person1.pet.breed = "Labrador";
    person1.pet.dog_age = 3;
    
    Person person2;
    person2.name = "Bob";
    person2.pet.name = "Max";
    person2.pet.breed = "Golden Retriever";
    person2.pet.dog_age = 2;
    
    myHouse.addPerson(person1);
    myHouse.addPerson(person2);
    
    myHouse.displayPersonsDetails();

    return 0;
}
