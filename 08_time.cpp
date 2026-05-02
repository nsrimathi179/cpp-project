#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    Time operator+(const Time& t) {
        int totalSeconds = seconds + t.seconds;
        int totalMinutes = minutes + t.minutes + totalSeconds / 60;
        int totalHours = hours + t.hours + totalMinutes / 60;
        return Time(totalHours % 24, totalMinutes % 60, totalSeconds % 60);
    }

    void display() {
        cout << hours << "h " << minutes << "m " << seconds << "s" << endl;
    }
};

int main() {
    Time t1(1, 45, 50);
    Time t2(0, 30, 20);
    Time t3 = t1 + t2;
    cout << "Time 1: "; t1.display();
    cout << "Time 2: "; t2.display();
    cout << "Sum:    "; t3.display();
    return 0;
}
