#include <iostream>
using namespace std;

class Matrix {
private:
    int data[2][2];

public:
    Matrix(int a, int b, int c, int d) {
        data[0][0] = a; data[0][1] = b;
        data[1][0] = c; data[1][1] = d;
    }

    Matrix operator+(const Matrix& m) {
        return Matrix(
            data[0][0] + m.data[0][0], data[0][1] + m.data[0][1],
            data[1][0] + m.data[1][0], data[1][1] + m.data[1][1]
        );
    }

    Matrix operator-(const Matrix& m) {
        return Matrix(
            data[0][0] - m.data[0][0], data[0][1] - m.data[0][1],
            data[1][0] - m.data[1][0], data[1][1] - m.data[1][1]
        );
    }

    Matrix operator*(const Matrix& m) {
        return Matrix(
            data[0][0]*m.data[0][0] + data[0][1]*m.data[1][0],
            data[0][0]*m.data[0][1] + data[0][1]*m.data[1][1],
            data[1][0]*m.data[0][0] + data[1][1]*m.data[1][0],
            data[1][0]*m.data[0][1] + data[1][1]*m.data[1][1]
        );
    }

    void display() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix m1(1, 2, 3, 4);
    Matrix m2(5, 6, 7, 8);
    cout << "Sum:" << endl; (m1 + m2).display();
    cout << "Diff:" << endl; (m1 - m2).display();
    cout << "Product:" << endl; (m1 * m2).display();
    return 0;
}
