#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    T1 getFirst() { return first; }
    T2 getSecond() { return second; }

    void display() {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

int main() {
    Pair<int, string> p1(1, "One");
    Pair<string, double> p2("Pi", 3.14159);
    Pair<char, bool> p3('A', true);

    p1.display();
    p2.display();
    p3.display();
    return 0;
}
