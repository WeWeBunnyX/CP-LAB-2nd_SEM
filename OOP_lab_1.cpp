class Dog {
public:
string name; void bark() {
cout << name << " says Woof!" « endl;
}
};
class Person { public:
string name; Dog pet;
void introducePet() {
cout « "My dog's name is " « pet.name « endl; pet.bark();
}
};
int main() {
Person personl;
personl.name = "Alice";
personl.pet.name = "Buddy"; personl.introducePet();
return 0;
}

