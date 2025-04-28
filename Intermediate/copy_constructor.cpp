//this is using the default copy constructor which does a shallow copy...i.e. only values are copied and not the actual memory details. Both objects point to the same memory location. So chaning one changes the original value too
// #include<bits/stdc++.h>
// using namespace std;
// class Parent{
//     private:
//         int income;
//     public:
//         string name;
// };
// class Children:public Parent{
//     public:
//         string parentName;
//     Children(string _parentName){
//         this->parentName = _parentName;
//     }
// };
// int main(){
//     Children Ram("Shyam");
//     Children Mohan(Ram);
//     cout<<Mohan.parentName;//parent name is shyam
// }


//using customer defined deep copy:
#include <bits/stdc++.h>
using namespace std;

class Parent {
private:
    int income;
public:
    string name;
};

class Children : public Parent {
public:
    string parentName;
    int* age; // <-- new pointer

    // Constructor
    Children(string _parentName,int _age){
        this->parentName=_parentName;
        this->age = new int(_age);
    }
    Children(const Children& other) {
        parentName = other.parentName;
        age = new int(*(other.age)); // deep copy
    }

    // Destructor to free memory
    ~Children() {
        delete age;
    }
};

int main() {
    Children Ram("Shyam", 40);
    Children Mohan(Ram); // Default copy constructor

    cout << "Mohan's parent name: " << Mohan.parentName << endl;
    cout << "Mohan's parent age: " << *(Mohan.age) << endl;

    *(Ram.age) = 70; // Change Ram's age

    cout << "After changing Ram's age:" << endl;
    cout << "Mohan's parent age: " << *(Mohan.age) << endl; // Will also change!!

    return 0;
}

In serious coding (production level), memory leaks are a disaster 🧨, so rule is:

If you new, you must delete.
If you malloc, you must free.