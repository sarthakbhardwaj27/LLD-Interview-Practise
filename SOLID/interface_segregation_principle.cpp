/*
Clients (subclasses) should not be forced to depend on methods they do not use.
*/
class Workable {
    public:
        virtual void work() = 0;
        virtual ~Workable() {}
    };
    
    class Eatable {
    public:
        virtual void eat() = 0;
        virtual ~Eatable() {}
    };
    
    class HumanWorker : public Workable, public Eatable {
    public:
        void work() override {
            cout << "Human working..." << endl;
        }
        void eat() override {
            cout << "Human eating lunch..." << endl;
        }
    };
    
    class RobotWorker : public Workable {
    public:
        void work() override {
            cout << "Robot working..." << endl;
        }
    };
    