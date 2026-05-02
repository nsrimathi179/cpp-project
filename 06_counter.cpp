#include <iostream>
using namespace std;

class Counter {
private:
    int count;
    static int totalCounters;

public:
    Counter() : count(0) {
        totalCounters++;
    }

    void increment() { count++; }
    void decrement() { count--; }
    void reset() { count = 0; }
    int getCount() { return count; }

    static int getTotalCounters() {
        return totalCounters;
    }

    void display() {
        cout << "Count: " << count << endl;
    }
};

int Counter::totalCounters = 0;

int main() {
    Counter c1, c2;
    c1.increment();
    c1.increment();
    c2.increment();
    c1.decrement();
    c1.display();
    c2.display();
    cout << "Total counters created: " << Counter::getTotalCounters() << endl;
    return 0;
}
