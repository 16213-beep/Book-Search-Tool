#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    Book library[5];

    // Initialise books
    library[0].setBookDetails("Book: Lord Of The Rings: The Fellowship", "Author: J.R.R Tolkien", "101", true, "2024");
    library[1].setBookDetails("Book: Death in Paradise", "Author: J.E. Trent", "105", true, "2023");
    library[2].setBookDetails("Book: My Sister's Keeper", "Author: Jodi Picoult", "102", true, "2022");
    library[3].setBookDetails("Book: Life Of Pi", "Author: Yann Martel", "104", true, "2021");
    library[4].setBookDetails("Book: The Very Hungry Bear", "Author: Nick Bland", "103", true, "2020");

    // Sort books
    Book::sortBookData(library, 5);

    cout << "==========================" << endl;
    cout << "===   Library System   ===" << endl;
    cout << "==========================" << endl;

    int option;

    while (true) {

        cout << "==========================" << endl;
        cout << "===        Menu        ===" << endl;
        cout << "===   1 Display Books ===" << endl;
        cout << "===   2 Borrow Book   ===" << endl;
        cout << "===   3 Return Book   ===" << endl;
        cout << "===      4 Exit       ===" << endl;
        cout << "==========================" << endl;
        cout << "Select Option (1-4): ";
        cin >> option;

        // EXIT
        if (option == 4) {
            cout << "Thank you for choosing our Library!" << endl;
            break;
        }

        // DISPLAY BOOKS
        if (option == 1) {
            cout << "\nLibrary Books:\n";
            for (int i = 0; i < 5; i++) {
                library[i].displayBookDetails();
            }
        }

        // BORROW BOOK
        if (option == 2) {
            string inputISBN;
            cout << "Enter ISBN to borrow: ";
            cin >> inputISBN;

            bool found = false;

            for (int i = 0; i < 5; i++) {
                if (library[i].getISBN() == inputISBN) {
                    found = true;
                    library[i].borrowBook();
                    break;
                }
            }

            if (!found) {
                cout << "Error: Book not found." << endl;
            }
        }

        // RETURN BOOK
        if (option == 3) {
            string inputISBN;
            cout << "Enter ISBN to return: ";
            cin >> inputISBN;

            bool found = false;

            for (int i = 0; i < 5; i++) {
                if (library[i].getISBN() == inputISBN) {
                    found = true;
                    library[i].returnBook();
                    cout << "Book returned successfully." << endl;
                    break;
                }
            }

            if (!found) {
                cout << "Error: Book not found." << endl;
            }
        }

        // INVALID OPTION
        if (option < 1 || option > 4) {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}