#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

class FileHandler {
private:
    fstream file;
    string filename;

public:
    FileHandler(const string& fname, ios::openmode mode = ios::in | ios::out | ios::app) 
        : filename(fname) {
        file.open(fname, mode);
        if (!file.is_open())
            throw runtime_error("Failed to open file: " + fname);
        cout << "File opened: " << fname << endl;
    }

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            cout << "File closed: " << filename << endl;
        }
    }

    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;

    void write(const string& data) {
        file << data << "\n";
    }

    void readAll() {
        file.clear();
        file.seekg(0, ios::beg);
        string line;
        while (getline(file, line))
            cout << line << endl;
    }
};

int main() {
    try {
        FileHandler fh("test_raii.txt", ios::in | ios::out | ios::trunc);
        fh.write("Hello from RAII FileHandler");
        fh.write("Second line of data");
        cout << "File contents:" << endl;
        fh.readAll();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
