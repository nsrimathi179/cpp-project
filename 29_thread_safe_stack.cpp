#include <iostream>
#include <stack>
#include <mutex>
#include <thread>
using namespace std;

class ThreadSafeStack {
private:
    stack<int> data;
    mutable mutex mtx;

public:
    void push(int val) {
        lock_guard<mutex> lock(mtx);
        data.push(val);
    }

    void pop() {
        lock_guard<mutex> lock(mtx);
        if (!data.empty())
            data.pop();
    }

    int top() {
        lock_guard<mutex> lock(mtx);
        if (data.empty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return data.top();
    }

    bool empty() const {
        lock_guard<mutex> lock(mtx);
        return data.empty();
    }

    int size() const {
        lock_guard<mutex> lock(mtx);
        return data.size();
    }
};

void pushItems(ThreadSafeStack& s, int start) {
    for (int i = start; i < start + 5; i++)
        s.push(i);
}

int main() {
    ThreadSafeStack s;

    thread t1(pushItems, ref(s), 0);
    thread t2(pushItems, ref(s), 10);

    t1.join();
    t2.join();

    cout << "Stack size: " << s.size() << endl;
    cout << "Top: " << s.top() << endl;
    return 0;
}
