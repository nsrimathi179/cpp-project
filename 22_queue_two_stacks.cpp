#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> inbox;
    stack<int> outbox;

    void transfer() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
    }

public:
    void enqueue(int val) {
        inbox.push(val);
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        transfer();
        outbox.pop();
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        transfer();
        return outbox.top();
    }

    bool isEmpty() {
        return inbox.empty() && outbox.empty();
    }

    int size() {
        return inbox.size() + outbox.size();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.front() << endl;
    q.dequeue();
    cout << "Front after dequeue: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;
    return 0;
}
