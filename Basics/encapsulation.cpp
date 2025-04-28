#include <bits/stdc++.h>
using namespace std;

/*the below also abides encapulation logic
🔒 1. Encapsulation in Action
You've:

Made price private → Good encapsulation ✅

Provided a setter (setPrice) → Controlled access ✅

Hidden direct access to sensitive data (no car1.price = 100) ✅

🧠 2. Accessing Private Data via a Public Method
You used carDetails() to access the private price field — again, this is textbook encapsulation.

🏷️ 3. Use of this Pointer
Use of this->name and this->price is fine. While not mandatory (you could write just name and price), using this makes the code explicitly clear — which is great for readability.
*/
// class Car{
//     private:
//         int price;
//     public:
//         string name;
//     void startCar(){
//         cout<<"Car is running:"<<this->name<<endl;
//     }
//     void carDetails(){
//         cout<<"Car costs:"<<this->price<<endl;
//     }
//     void setPrice(int x){
//         this->price = x;
//     }
// };
// int main() {
//     // Write C++ code here
//     Car car1;
//     car1.name = "Audi";
//     car1.setPrice(100);
//     car1.startCar();
//     car1.carDetails();
//     return 0;
// }

// trying to use constructor for better code:
/*
class Car
{
private:
    string name;
    int price;

public:
    Car(string _name, int _price)
    {
        this->name = _name;
        this->price = _price;
    }
    string getName()
    {
        return this->name;
    }
};

int main()
{
    Car car1("Audi", 100);
    cout << "Car name is:" << car1.getName();
}
*/