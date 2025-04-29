// // instead of inheritance using composition (has-a relation): need to study this
// #include<iostream>
// #include<string>
// using namespace std;

// class Bank {
// private:
//     static int totalAccounts;
// public:
//     static void increaseTotalAccounts() {
//         totalAccounts++;
//     }
//     static int getTotalAccounts() {
//         return totalAccounts;
//     }
// };

// int Bank::totalAccounts = 0;

// class BankAccount {
// private:
//     int accountNumber;
//     string accountHolderName;
//     double balance;
// public:
//     BankAccount(int _accountNumber, string _accountHolderName) 
//         : accountNumber(_accountNumber), accountHolderName(_accountHolderName), balance(0) {
//         Bank::increaseTotalAccounts();   // Notice: call Bank's static method!
//     }

//     void deposit(double amount) {
//         balance += amount;
//         cout << amount << " has been deposited. Total balance: " << balance << endl;
//     }

//     void withdrawal(double amount) {
//         if (balance >= amount) {
//             balance -= amount;
//             cout << amount << " has been withdrawn. Total balance: " << balance << endl;
//         } else {
//             cout << "Insufficient Balance: " << balance << endl;
//         }
//     }

//     void display() const {
//         cout << "Account Number: " << accountNumber << endl;
//         cout << "Account Holder: " << accountHolderName << endl;
//         cout << "Current Balance: " << balance << endl;
//     }
// };

// int main() {
//     cout << "Total Bank accounts: " << Bank::getTotalAccounts() << endl;

//     BankAccount b1(1, "Sarthak");
//     b1.display();
//     b1.deposit(100);
//     b1.withdrawal(110);
//     b1.withdrawal(50);
//     b1.display();

//     cout << "Total Bank accounts: " << Bank::getTotalAccounts() << endl;
//     return 0;
// }

// //because the accountNumber value was static, no need for composition we simply referred by Bank::totalAccount;
// //if it was not static then the below would have worked as:
// class Bank; // Forward declaration

// class BankAccount {
// private:
//     int accountNumber;
//     string accountHolderName;
//     double balance;
//     Bank* bank;  // <-- BankAccount HAS-A Bank (via pointer)
// public:
//     BankAccount(int _accountNumber, string _accountHolderName, Bank* _bank) 
//         : accountNumber(_accountNumber), accountHolderName(_accountHolderName), balance(0), bank(_bank) {
//         bank->increaseTotalAccounts(); // <-- Notice object used, not class!
//     }
//     // other methods
// };

// class Bank {
// private:
//     int totalAccounts;
// public:
//     Bank() : totalAccounts(0) {}

//     void increaseTotalAccounts() {
//         totalAccounts++;
//     }

//     int getTotalAccounts() {
//         return totalAccounts;
//     }
// };

// int main() {
//     Bank bank;
//     BankAccount b1(1, "Sarthak", &bank);

//     cout << "Total Bank accounts: " << bank.getTotalAccounts() << endl;
//     return 0;
// }
