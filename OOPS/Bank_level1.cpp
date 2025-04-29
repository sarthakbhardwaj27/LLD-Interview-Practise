/*
Create a C++ program that models a Bank Account with the following:

A class BankAccount that has:

Private data members: accountNumber, accountHolderName, and balance.

A constructor to initialize these values.

Member functions:

deposit(double amount) to add money.

withdraw(double amount) to remove money (only if sufficient balance).

display() to print account details.

Extra Challenge (optional):

Add a static data member that keeps track of the total number of accounts created.
*/

#include<bits/stdc++.h>
using namespace std;


class Bank{
    private:
        static int totalAccounts;
    public:
        int getTotalAccounts(){
            return this->totalAccounts;
        }
        void increaseTotalAccounts(){
            this->totalAccounts++;
        }
};
int Bank::totalAccounts = 0;

class BankAccount : public Bank{
    private:
        int accountNumber;
        string accountHolderName;
        double balance;
    public:
        double getBalance(){
            return this->balance;
        }
        void setBalance(double _newBalance){
            this->balance = _newBalance;
        }
        void deposit(double amount){
            double currBalance = getBalance();
            currBalance+=amount;
            setBalance(currBalance);
            cout<<amount<<" has been added. Total balance is: "<<currBalance<<endl;
        }
        void withdrawl(double amount){
            double currBalance = getBalance();
            if(currBalance >= amount){
                currBalance-=amount;
                setBalance(currBalance);
                cout<<amount<<" has been withdrawn. Total balance is: "<<currBalance<<endl;
            }else{
                cout<<"Insufficient Balance: "<<currBalance<<endl;
            }
        }
        void display(){
            double currBalance = getBalance();
            cout<<"Current balance is:"<<currBalance<<endl;
        }
        BankAccount(int _accountNumber, string _accountHolderName){
            this->accountNumber = _accountNumber;
            this->accountHolderName = _accountHolderName;
            this->balance = 0;
            this->increaseTotalAccounts();
        }

};
int main(){
    Bank bank1;
    cout<<"Total Bank accounts are: "<<bank1.getTotalAccounts();

    BankAccount b1(1,"Sarthak");
    b1.display();
    b1.deposit(100);
    b1.withdrawl(110);
    b1.withdrawl(50);
    b1.display();
    cout<<"Total Bank accounts are: "<<bank1.getTotalAccounts()<<endl;
    return 0;
}