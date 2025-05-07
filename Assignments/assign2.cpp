#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Book class
class Book {
protected:
    string bookID, title, author, genre;
    bool availabilityStatus;

public:

    // Constructor
    Book(string id, string t, string a, string g) 
        : bookID(id), title(t), author(a), genre(g), availabilityStatus(true) {}

    // Display book info
    virtual void displayBookInfo() {
        cout << "ID: " << bookID << "\nTitle: " << title 
             << "\nAuthor: " << author << "\nGenre: " << genre
             << "\nStatus: " << (availabilityStatus ? "Available" : "Borrowed") << endl;
    }

    // Borrow/return methods
    void borrowBook() { availabilityStatus = false; }
    void returnBook() { availabilityStatus = true; }

    // Getters
    string getID() { return bookID; }
    string getTitle() { return title; }
    bool isAvailable() { return availabilityStatus; }
};

// Derived EBook class
class EBook : public Book {
    double fileSize; // in MB

public:
    EBook(string id, string t, string a, string g, double fs) 
        : Book(id, t, a, g), fileSize(fs) {}

    // Override display method
    void displayBookInfo() override {
        Book::displayBookInfo();
        cout << "File Size: " << fileSize << "MB" << endl;
    }
};

// Member class
class Member {
    string memberID, name;
    vector<string> borrowedBooks;

public:
    // Constructor
    Member(string id, string n) : memberID(id), name(n) {}

    // Borrow/return methods
    void borrowBook(Book &book) {
        if (book.isAvailable()) {
            borrowedBooks.push_back(book.getID());
            book.borrowBook();
            cout << "Book borrowed successfully!" << endl;
        } else {
            cout << "Book not available!" << endl;
        }
    }

    void returnBook(Book &book) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if (*it == book.getID()) {
                borrowedBooks.erase(it);
                book.returnBook();
                cout << "Book returned successfully!" << endl;
                return;
            }
        }
        cout << "Book not found in your borrowed list!" << endl;
    }

    // Display member info
    void displayMemberInfo() {
        cout << "Member ID: " << memberID << "\nName: " << name 
             << "\nBorrowed Books: " << borrowedBooks.size() << endl;
    }
};

// Library class
class Library {
    vector<Book*> books;
    vector<Member> members;

public:
    // Add book to library
    void addBook(Book* book) {
        books.push_back(book);
    }

    // Add member to library
    void addMember(Member member) {
        members.push_back(member);
    }

    // Display all books
    void displayAllBooks() {
        cout << "\nLibrary Books:\n";
        for (auto book : books) {
            book->displayBookInfo();
            cout << "----------------\n";
        }
    }

    // Search book by title
    void searchBook(string title) {
        bool found = false;
        for (auto book : books) {
            if (book->getTitle() == title) {
                book->displayBookInfo();
                found = true;
                break;
            }
        }
        if (!found) cout << "Book not found!" << endl;
    }
};

int main() {
    // Create library instance
    Library library;

    // Add books
    Book book1("B001", "C++ Programming", "Bjarne Stroustrup", "Computer Science");
    EBook ebook1("EB001", "Clean Code", "Robert Martin", "Programming", 5.2);
    library.addBook(&book1);
    library.addBook(&ebook1);

    // Add members
    Member member1("M001", "John Doe");
    library.addMember(member1);

    // Test functionalities
    cout << "--- Library System Test ---\n";
    library.displayAllBooks();

    cout << "\nSearching for 'Clean Code':\n";
    library.searchBook("Clean Code");

    cout << "\nMember borrowing book:\n";
    member1.borrowBook(book1);

    cout << "\nUpdated book status:\n";
    book1.displayBookInfo();

    return 0;
}
