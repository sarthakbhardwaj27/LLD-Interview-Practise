/*Abstraction is: hiding unnecessary implementation details from the user*/
#include<bits/stdc++.h>
using namespace std;
class Engine{
    public:
        void start(){
            cout<<"Engine started"<<endl;
        }
};
class Car{
    private:
        Engine engine;
    public:
        void drive(){
            engine.start(); //abstracted this section
            cout<<"Car is moving"<<endl;
        }
};

int main(){
    Car car1;
    car1.drive();
}