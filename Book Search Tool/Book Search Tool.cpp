#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    Book library[5];

    // Initialise books
    library[0].setBookDetails("Book A", "Author A", "101", true, "2024");
    library[1].setBookDetails("Book B", "Author B", "105", true, "2023");
    library[2].setBookDetails("Book C", "Author C", "102", true, "2022");
    library[3].setBookDetails("Book D", "Author D", "104", true, "2021");
    library[4].setBookDetails("Book E", "Author E", "103", true, "2020");

    // Sort books
    Book::sortBookData(library, 5);

    // Display books
    cout << "Library Books:\n";
    for (int i = 0; i < 5; i++) {
        library[i].displayBookDetails();
    }

    string inputISBN;

    while (true) {
        cout << "Enter ISBN to borrow (0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (library[i].getISBN() == inputISBN) {
                found = true;
                library[i].borrowBook();
                break;
            }
        }

        if (!found) {
            cout << "Error: Book not found.\n";
        }
    }

    cout << "Program ended.\n";
    return 0;
}