#include<bits/stdc++.h>
using namespace std;
class Vehicle{
    public:
    static int vehicleCount;
    string name;
    Vehicle(string _name){
        this->name=_name;
        cout<<name<<" vehicle has been created"<<endl;
        vehicleCount++;
    }
};
int Vehicle::vehicleCount = 0;
int main(){
    Vehicle car("Alto");
    Vehicle bike("ktm");
    Vehicle truck("volvo");
    Vehicle maruti(car);//this will not add to the static counter value
    cout<<Vehicle::vehicleCount<<endl;
}