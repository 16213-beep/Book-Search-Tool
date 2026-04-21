#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    Book library[5];

    // Initialise books
    library[0].setBookDetails("The Lord Of The Rings: The Fellowship", "J.R.R Tolkien", "986-4-15-125367-7", true, "04/02/2024");
    library[1].setBookDetails("Death in Paradise", "J.E. Trent", "945-1-22-542980-0", true, "15/06/2023");
    library[2].setBookDetails("My Sister's Keeper", "Jodi Picoult", "917-6-57-837294-4", true, "28/10/2022");
    library[3].setBookDetails("Life Of Pi", "Yann Martel", "953-2-77-926539-9", true, "02/01/2021");
    library[4].setBookDetails("The Very Hungry Bear", "Nick Bland", "928-8-48-857365-5", true, "29/05/2020");

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