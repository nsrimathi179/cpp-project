#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    virtual void update(int state) = 0;
    virtual ~Observer() {}
};

class Subject {
private:
    int state;
    vector<Observer*> observers;

public:
    Subject() : state(0) {}

    void attach(Observer* o) {
        observers.push_back(o);
    }

    void detach(Observer* o) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == o) {
                observers.erase(it);
                return;
            }
        }
    }

    void setState(int s) {
        state = s;
        notifyAll();
    }

    int getState() { return state; }

    void notifyAll() {
        for (Observer* o : observers)
            o->update(state);
    }
};

class ConcreteObserver : public Observer {
private:
    string name;

public:
    ConcreteObserver(string n) : name(n) {}

    void update(int state) override {
        cout << name << " notified. New state: " << state << endl;
    }
};

int main() {
    Subject subject;
    ConcreteObserver obs1("Observer A");
    ConcreteObserver obs2("Observer B");
    ConcreteObserver obs3("Observer C");

    subject.attach(&obs1);
    subject.attach(&obs2);
    subject.attach(&obs3);

    subject.setState(10);
    subject.detach(&obs2);
    subject.setState(20);
    return 0;
}
