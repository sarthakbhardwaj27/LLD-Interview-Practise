/*Inheritance is the mechanism to derive a class from another class*/
#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    void walk()
    {
        cout << "Animal is walking.." << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Dog is barking" << endl;
    }
};
int main()
{
    Dog d1;
    d1.walk();//inherited from parent
    d1.speak();
}