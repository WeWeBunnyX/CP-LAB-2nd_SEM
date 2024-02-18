
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
    void changePet(const Dog &newPet) {
        pet = newPet;
    }
};
class House {
private:
    vector<Person> residents;
    Person owner;
public:
    void addPerson(const Person &person) {
        residents.push_back(person);
    }
    void setOwner(Person &person) {
        owner = person;
    }
    void displayResidents() {
        cout << "Residents of the house:" << endl;
        for (auto &resident : residents) {
            resident.introduce();
            cout << endl;
        }
    }
    void displayOwnerDetails() {
        cout << "House Owner's Details:" << endl;
        owner.introduce();
    }
    void changeOwnerPet(const Dog &newPet) {
        owner.changePet(newPet);
    }
};
class Neighborhood {
private:
    vector<House> houses;
public:
    void addHouse(const House &house) {
        houses.push_back(house);
    }
    void displayHouses() {
        for (int i = 0; i < houses.size(); i++) {
            cout << "\nHouse " << i+1 << ":" << endl;
            houses[i].displayResidents();
            houses[i].displayOwnerDetails();
            cout << endl;
        }
    }
};

class Vehicle {
private:
    string make;
    string model;
    int year;
    int mileage;
public:
    Vehicle(string mk, string mdl, int yr, int mil) : make(mk), model(mdl), year(yr), mileage(mil) {}
    void setMake(string mk) { 
        make = mk;
    }
    void setModel(string mdl) {
        model = mdl;
    }
    void setYear(int yr) {
        year = yr;
    }
    void setMileage(int mil) {
        mileage = mil;
    }
    void displayVehicleInfo() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", Mileage: " << mileage << endl;
        if(mileage > 10000) {
            cout << "Car needs servicing!" << endl;
            
        }
    }
};


int main() {
    House myHouse;
    // Adding residents
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

    // Setting the house owner
    Person owner;
    owner.name = "Alice";
    owner.age = 30;
    Dog dog;
    dog.name = "Buddy";
    dog.breed = "Labrador";
    dog.dog_age = 3;
    owner.pet = dog;
    myHouse.setOwner(owner);

    // Displaying owner's details
    myHouse.displayOwnerDetails();

    // Changing the pet (new pet)
    Dog newPet;
    newPet.name = "Duggie";
    newPet.breed = "Shiba";
    newPet.dog_age = 5;
    myHouse.changeOwnerPet(newPet);

    // Changed Pet 
    cout << "\nNew Pet:" << endl;
    myHouse.displayOwnerDetails();
    Neighborhood myNeighborhood;
    myNeighborhood.addHouse(myHouse);

    // Creating another house
    House myHouse2;

    // Adding residents
    Person person4;
    person4.name = "John";
    person4.age = 40;
    person4.pet.name = "Rex";
    person4.pet.breed = "German Shepherd";
    person4.pet.dog_age = 4;

    Person person5;
    person5.name = "Jane";
    person5.age = 30;
    person5.pet.name = "Bell";
    person5.pet.breed = "Frenchie";
    person5.pet.dog_age = 3;
    myHouse2.addPerson(person4);
    myHouse2.addPerson(person5);

    // Setting the house owner of second house we added above
    Person owner2;
    owner2.name = "John";
    owner2.age = 38;
    Dog dog2;
    dog2.name = "Rex";
    dog2.breed = "German Shepherd";
    dog2.dog_age = 4;
    owner2.pet = dog2;
    myHouse2.setOwner(owner2);

    // Adding the second house to the neighborhood
    myNeighborhood.addHouse(myHouse2);
    // Displaying the details of all houses present in the neighborhood
    myNeighborhood.displayHouses();


    Vehicle myVehicle("Toyota", "Prius", 2015, 15000);
    myVehicle.displayVehicleInfo();
    // New Car addition using setModel and setYear
    myVehicle.setModel("Land Cruiser");
    myVehicle.setYear(2022);
    myVehicle.setMileage(5000);
    myVehicle.displayVehicleInfo();
    return 0;
}






