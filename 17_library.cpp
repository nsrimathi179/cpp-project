#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    string author;

    Book(string t, string a) : title(t), author(a) {}

    void display() {
        cout << "\"" << title << "\" by " << author << endl;
    }
};

class Library {
private:
    vector<Book*> books;

public:
    ~Library() {
        for (Book* b : books)
            delete b;
    }

    void addBook(string title, string author) {
        books.push_back(new Book(title, author));
    }

    void removeBook(string title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->title == title) {
                delete *it;
                books.erase(it);
                cout << "Removed: " << title << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void displayAll() {
        cout << "Library Collection:" << endl;
        for (Book* b : books)
            b->display();
    }
};

int main() {
    Library lib;
    lib.addBook("1984", "George Orwell");
    lib.addBook("Dune", "Frank Herbert");
    lib.addBook("Neuromancer", "William Gibson");
    lib.displayAll();
    cout << "---" << endl;
    lib.removeBook("Dune");
    lib.displayAll();
    return 0;
}
