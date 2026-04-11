#pragma once
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool availability;
    string dateAdd;

public:
    void setBookDetails(string t, string a, string i, bool avail, string d);
    void displayBookDetails();
    void borrowBook();
    void returnBook();

    string getISBN();
    bool isAvailable();

    static void sortBookData(Book books[], int size);
};
