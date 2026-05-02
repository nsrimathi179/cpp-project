#include <iostream>
#include <cstring>
using namespace std;

class StringWrapper {
private:
    char* data;
    int length;

public:
    StringWrapper(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    StringWrapper(const StringWrapper& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    ~StringWrapper() {
        delete[] data;
    }

    StringWrapper operator+(const StringWrapper& other) {
        char* temp = new char[length + other.length + 1];
        strcpy(temp, data);
        strcat(temp, other.data);
        StringWrapper result(temp);
        delete[] temp;
        return result;
    }

    bool operator==(const StringWrapper& other) {
        return strcmp(data, other.data) == 0;
    }

    char operator[](int index) {
        return data[index];
    }

    void display() {
        cout << data << endl;
    }
};

int main() {
    StringWrapper s1("Hello, ");
    StringWrapper s2("World!");
    StringWrapper s3 = s1 + s2;
    s3.display();
    cout << "Equal: " << (s1 == s2 ? "Yes" : "No") << endl;
    cout << "Char at 0: " << s1[0] << endl;
    return 0;
}
