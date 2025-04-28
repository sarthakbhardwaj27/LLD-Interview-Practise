/*Polymorphism lets you treat different types as if they are the same and c++ figures out which behaviour to run at runtime*/
/*
You can tell any employee to work(), and they’ll do different things based on their role:

Developer → writes code

Manager → attends meetings

Designer → makes UI

But you just call: employee->work();
You don’t need to care who exactly they are.
*/

//MY CODE VVVV
// #include<bits/stdc++.h>
// using namespace std;
// class Employee{
//     private: 
//         string name;
//         //static int employeeId=0;//why cant i use static for maintaing a universal count?
//     public: 
//         virtual void work(){};
//         void setName(string _name){
//             this->name = _name;
//         }
//         string getName(){
//             return this->name;
//         }

// };
// class Manager: public Employee{
//     public:
//         Manager(string n){
//             setName(n);
//         }
//         void work() override{
//             cout<<this->getName()<<" is a manager attending meetings"<<endl;
//         }
// };

// class Developer: public Employee{
//     public:
//         Developer(string n){
//             setName(n);
//         }
//         void work() override{
//             cout<<this->getName()<<" is a developer who makes code"<<endl;
//         }
// };

// class Designer: public Employee{
//     public:
//         Designer(string n){
//             setName(n);
//         }
//         void work() override{
//             cout<<this->getName()<<" is a designer working on UI"<<endl;
//         }
// };

// int main(){
//     Employee* e1 = new Manager("Arun");
//     Employee* e2 = new Developer("Sarthak");
//     Employee* e3 = new Designer("Ram");
//     e1->work();
//     e2->work();
//     e3->work();
// }

//CHATGPT CODE:
// #include <bits/stdc++.h>
// using namespace std;

// class Employee {
// private:
//     string name;
//     int employeeId;
//     static int idCounter; // Shared across all employees

// public:
//     Employee(string _name) {
//         this->name = _name;
//         this->employeeId = ++idCounter; // Increment and assign
//     }

//     virtual void work() = 0; // Pure virtual (interface-like)

//     void setName(string _name) {
//         this->name = _name;
//     }

//     string getName() const {
//         return this->name;
//     }

//     int getId() const {
//         return this->employeeId;
//     }

//     virtual ~Employee() {} // virtual destructor
// };

// // Initialize static member
// int Employee::idCounter = 0;

// class Manager : public Employee {
// public:
//     Manager(string n) : Employee(n) {}

//     void work() override {
//         cout << getName() << " (ID: " << getId() << ") is a manager attending meetings" << endl;
//     }
// };

// class Developer : public Employee {
// public:
//     Developer(string n) : Employee(n) {}

//     void work() override {
//         cout << getName() << " (ID: " << getId() << ") is a developer who makes code" << endl;
//     }
// };

// class Designer : public Employee {
// public:
//     Designer(string n) : Employee(n) {} //THIS IS CALLED CONSTRUCTOR INITIALIZATION LIST (RECOMMEDED) BUT YOU NEED A CONSTRUCTOR OF THE PARENT CLASS FIRST

//     void work() override {
//         cout << getName() << " (ID: " << getId() << ") is a designer working on UI" << endl;
//     }
// };

// int main() {
//     Employee* e1 = new Manager("Arun");
//     Employee* e2 = new Developer("Sarthak");
//     Employee* e3 = new Designer("Ram");

//     e1->work();
//     e2->work();
//     e3->work();

//     delete e1;
//     delete e2;
//     delete e3;

//     return 0;
// }


//one level deeper with junior and senior developers;
#include <bits/stdc++.h>
using namespace std;

// Base class: Employee
class Employee {
private:
    string name;
    static int idCounter;
    int employeeId;

public:
    Employee(string _name) {
        name = _name;
        employeeId = ++idCounter;  // Assign unique ID
    }

    virtual void work() = 0; // Pure virtual method

    void setName(string _name) {
        name = _name;
    }

    string getName() const {
        return name;
    }

    int getId() const {
        return employeeId;
    }

    static int getTotalEmployees() {
        return idCounter;
    }
};

// Initialize static member
int Employee::idCounter = 0;

// Developer class (Intermediate class for Senior and Junior developers)
class Developer : public Employee {
public:
    Developer(string n) : Employee(n) {}

    virtual void work() override {
        cout << getName() << " (ID: " << getId() << ") is a developer who writes code." << endl;
    }
};

// Senior Developer class
class SeniorDeveloper : public Developer {
public:
    SeniorDeveloper(string n) : Developer(n) {}

    void work() override {
        cout << getName() << " (ID: " << getId() << ") is a senior developer leading the development team and writing complex code." << endl;
    }
};

// Junior Developer class
class JuniorDeveloper : public Developer {
public:
    JuniorDeveloper(string n) : Developer(n) {}

    void work() override {
        cout << getName() << " (ID: " << getId() << ") is a junior developer working on simple tasks and learning." << endl;
    }
};

int main() {
    Employee* e1 = new SeniorDeveloper("Alice");
    Employee* e2 = new JuniorDeveloper("Bob");

    e1->work();  // Polymorphism in action
    e2->work();  // Different behavior for Junior Developer

    // Output total number of employees created
    cout << "Total employees created: " << Employee::getTotalEmployees() << endl;

    // Clean up memory
    delete e1;
    delete e2;

    return 0;
}
