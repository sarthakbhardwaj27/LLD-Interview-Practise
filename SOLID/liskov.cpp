/*
🧠 Intuitive understanding:
If S is a subtype of T, then objects of type T should be replaceable with objects of type S without breaking the program.

🔥 Simple meaning:
Wherever a parent class object is expected, you should be able to use a child class object without any surprises.

Child class must behave properly like its parent.
*/
#include <bits/stdc++.h>
using namespace std;

class Vehicle {
public:
    virtual void move() {
        cout << "Vehicle is moving" << endl;
    }
    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle {
public:
    void move() override {
        cout << "Bicycle is pedaling forward" << endl;
    }
};

class Car : public Vehicle {
public:
    void move() override {
        cout << "Car is driving forward" << endl;
    }
};

void startJourney(Vehicle* v) {
    v->move();
}

int main() {
    Vehicle* v1 = new Car();
    Vehicle* v2 = new Bicycle();

    startJourney(v1); // "Car is driving forward"
    startJourney(v2); // "Bicycle is pedaling forward"

    delete v1;
    delete v2;
    return 0;
}
