
#include "Book.h"

// Assign values
void Book::setBookDetails(string t, string a, string i, bool avail, string d) {
    title = t;
    author = a;
    ISBN = i;
    availability = avail;
    dateAdd = d;
}

// Display details
void Book::displayBookDetails() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Available: " << (availability ? "Yes" : "No") << endl;
    cout << "------------------------" << endl;
}

// Borrow book
void Book::borrowBook() {
    if (availability) {
        availability = false;
        cout << "Book borrowed successfully.\n";
    }
    else {
        cout << "Error: Book already borrowed.\n";
    }
}

// Return book
void Book::returnBook() {
    availability = true;
}

// Getter for ISBN
string Book::getISBN() {
    return ISBN;
}

// Check availability
bool Book::isAvailable() {
    return availability;
}

// Bubble Sort
void Book::sortBookData(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].getISBN() > books[j + 1].getISBN()) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}