#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Account{
    private:
        static int AccountNumber;
        string AccountHolderName;
        double balance;
        vector<string> transactionHistory;
        string accountType;

    public:
        double getBalance(){
            return balance;
        }
        void setBalance(double _amount){
            balance+=_amount;
        }
        void appendTransactionHistory(string transaction){
            transactionHistory.push_back(transaction);
        }
        void deposit(double _amount){
            balance+=_amount;
            cout<<_amount<<" has been deposited."<<endl;
            string transaction = "Deposited "+to_string(_amount);
            appendTransactionHistory(transaction);
        }

        virtual void withdraw(double _amount) = 0; //pure virtual function

        void display(){
            cout<<"Account Holder: "<<AccountHolderName<<endl;
            cout<<"Account Number: "<<AccountNumber<<endl;
            cout<<"Account Type: "<<accountType<<endl;
            cout<<"Transaction History:"<<endl;
            for(auto it:transactionHistory){
                cout<<it<<endl;
            }
            cout<<"---------------------"<<endl;
        }

        Account(string _AccountHolderName, string _accountType){
            this->AccountNumber++;
            this->AccountHolderName = _AccountHolderName;
            this->balance = 0;
            this->transactionHistory = {};
            this->accountType = _accountType;
        }

        ~Account(){ cout << "\nDestructor executed"; }
};

int Account::AccountNumber = 1000;

class interestHelper{
    public:
    double calulcateInterestRate(double interestRate,double &balance){
        balance=balance+(interestRate*0.01 + balance);
        return balance;
    }
};

class Savings : public Account, public interestHelper{
    private:
        double minimumRequiredBalance = 100.00;
        double interestRate = 10.00;

    public:
        void withdraw(double _amount) override{
            if(getBalance() < minimumRequiredBalance || (getBalance() - _amount) < minimumRequiredBalance){
                cout << "This breaches the minimum balance policy" << endl;
            } else {
                setBalance(getBalance() - _amount);
                string transaction = "Withdrawn " + to_string(_amount);
                appendTransactionHistory(transaction);
                cout << "Amount has been withdrawn" << endl;
            }
        }

        void setInterest(){
            double currBalance = getBalance();
            currBalance = calulcateInterestRate(interestRate, currBalance);
            setBalance(currBalance);
        }

        Savings(string holderName) : Account(holderName, "SavingsAccount") {}
};

class Current : public Account{
    private:
        double minimumRequiredBalance = 0;

    public:
        void withdraw(double _amount) override{
            if(getBalance() < minimumRequiredBalance || (getBalance() - _amount) < minimumRequiredBalance){
                cout << "This breaches the minimum balance policy" << endl;
            } else {
                setBalance(getBalance() - _amount);
                string transaction = "Withdrawn " + to_string(_amount);
                appendTransactionHistory(transaction);
                cout << "Amount has been withdrawn" << endl;
            }
        }

        Current(string holderName) : Account(holderName, "CurrentAccount") {}
};

int main() {
    Savings s1("Sarthak");
    s1.deposit(500);
    s1.withdraw(300);
    s1.display();

    Current c1("John");
    c1.deposit(1000);
    c1.withdraw(1200);
    c1.display();
}
