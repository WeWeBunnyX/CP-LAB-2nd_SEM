class Dog {
public:
string name; void bark() {
cout << name << " says Woof!" « endl;
}
};

class Person { public:
string name;
string breed;
int dog_age;

Dog pet;
void introducePet() {
cout « "My dog's name is " « pet.name « endl; 
cout<<"Breed: "<<pet.breed<<endl;
cout<<"Age: " <<pet.age<<endl;

pet.bark();
}
};




int main() {
Person personl;
personl.name = "Alice";
personl.pet.name = "Buddy"; 
personl.introducePet();
return 0;
}

