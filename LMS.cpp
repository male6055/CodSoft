#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
};

struct Borrower {
    string name;
    int borrowerID;
};

struct Transaction {
    int borrowerID;
    string ISBN;
    time_t checkoutDate;
    time_t dueDate;
    bool isReturned;
};

vector<Book> books;
vector<Borrower> borrowers;
vector<Transaction> transactions;

void addBook() {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter book author: ";
    getline(cin, newBook.author);
    cout << "Enter book ISBN: ";
    getline(cin, newBook.ISBN);
    newBook.isAvailable = true;
    books.push_back(newBook);
    cout << "Book added successfully.\n";
}

void searchBook() {
    string query;
    cout << "Enter book title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);

    for (const auto& book : books) {
        if (book.title == query || book.author == query || book.ISBN == query) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN
                 << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
        }
    }
}

void addBorrower() {
    Borrower newBorrower;
    cout << "Enter borrower name: ";
    cin.ignore();
    getline(cin, newBorrower.name);
    newBorrower.borrowerID = borrowers.size() + 1;
    borrowers.push_back(newBorrower);
    cout << "Borrower added successfully with ID: " << newBorrower.borrowerID << "\n";
}

void checkoutBook() {
    int borrowerID;
    string ISBN;
    cout << "Enter borrower ID: ";
    cin >> borrowerID;
    cout << "Enter book ISBN: ";
    cin >> ISBN;

    for (auto& book : books) {
        if (book.ISBN == ISBN && book.isAvailable) {
            book.isAvailable = false;
            time_t now = time(0);
            time_t due = now + (7 * 24 * 60 * 60); // Due in 7 days

            transactions.push_back({borrowerID, ISBN, now, due, false});
            cout << "Book checked out successfully.\n";
            return;
        }
    }
    cout << "Book not available or invalid ISBN.\n";
}

void returnBook() {
    int borrowerID;
    string ISBN;
    cout << "Enter borrower ID: ";
    cin >> borrowerID;
    cout << "Enter book ISBN: ";
    cin >> ISBN;

    for (auto& trans : transactions) {
        if (trans.borrowerID == borrowerID && trans.ISBN == ISBN && !trans.isReturned) {
            trans.isReturned = true;

            for (auto& book : books) {
                if (book.ISBN == ISBN) {
                    book.isAvailable = true;
                    break;
                }
            }

            time_t now = time(0);
            if (now > trans.dueDate) {
                double daysLate = difftime(now, trans.dueDate) / (60 * 60 * 24);
                double fine = daysLate * 0.50; // Assuming $0.50 per day
                cout << "Book returned late. Fine: $" << fine << "\n";
            } else {
                cout << "Book returned on time.\n";
            }
            return;
        }
    }
    cout << "Invalid return information.\n";
}

void showMenu() {
    cout << "Library Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book\n";
    cout << "3. Add Borrower\n";
    cout << "4. Checkout Book\n";
    cout << "5. Return Book\n";
    cout << "6. Exit\n";
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                addBorrower();
                break;
            case 4:
                checkoutBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
