
#include <iostream>
using namespace std;
class Plant {
protected:
    double height; // in centimeters
    double growthRate; // cm per day
public:
    Plant(double initialHeight, double growthRate) : height(initialHeight), growthRate(growthRate) {}
    virtual void grow() {
        height += growthRate;
    }
    virtual void displayHeight() const = 0;
};
class Flower : public Plant {
public:
    Flower(double initialHeight) : Plant(initialHeight, 0.5) {}
    void displayHeight() const override {
        cout << "Flower height: " << height << " cm" << endl;
    }
};
class Tree : public Plant {
public:
    Tree(double initialHeight) : Plant(initialHeight, 0.2) {}
    void displayHeight() const override {
        cout << "Tree height: " << height << " cm" << endl;
    }
};
class Bush : public Plant {
public:
    Bush(double initialHeight) : Plant(initialHeight, 0.7) {}
    void displayHeight() const override {
        cout << "Bush height: " << height << " cm" << endl;
    }
};
int main() {
    Flower flower(15);
    Tree tree(22);
    Bush bush(12);
    for (int i = 0; i < 30; i++) {
        flower.grow();
        tree.grow();
        bush.grow();
    }
    
    flower.displayHeight();
    tree.displayHeight();
    bush.displayHeight();
    return 0;
}
