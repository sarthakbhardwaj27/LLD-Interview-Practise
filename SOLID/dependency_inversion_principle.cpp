#include<bits/stdc++.h>
using namespace std;
// Abstraction
class IGameConsole {
    public:
        virtual void playGame() = 0;
        virtual ~IGameConsole() {}
    };
    
    // High-Level Module: User
    class User {
    private:
        IGameConsole* console;
    public:
        User(IGameConsole* c) : console(c) {}
        void play() {
            console->playGame();
        }
    };
    
    // Low-Level Modules: Xbox, PlayStation
    class Xbox : public IGameConsole {
    public:
        void playGame() override {
            cout << "Playing on Xbox!" << endl;
        }
    };
    
    class PlayStation : public IGameConsole {
    public:
        void playGame() override {
            cout << "Playing on PlayStation!" << endl;
        }
    };
    
    // Main function
    int main() {
        IGameConsole* xbox = new Xbox();
        IGameConsole* ps = new PlayStation();
    
        User user1(xbox);   // User playing on Xbox
        user1.play();
    
        User user2(ps);     // User playing on PlayStation
        user2.play();
    
        delete xbox;
        delete ps;
    }
    