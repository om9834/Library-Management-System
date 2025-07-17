#include <iostream>
#include <fstream>
#include <string>
#include "book.h"

using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    int id;
    string title, author;
};

Book books[MAX_BOOKS];
int bookCount = 0;

void addBookToFile() {
    ofstream fout("books.txt", ios::app);
    Book b;
    cout << "Enter Book ID: ";
    cin >> b.id;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, b.title);
    cout << "Enter Author: ";
    getline(cin, b.author);
    fout << b.id << "|" << b.title << "|" << b.author << "\n";
    fout.close();
    cout << "Book saved!\n";
}

void loadBooksFromFile() {
    ifstream fin("books.txt");
    string line;
    bookCount = 0;

    while (getline(fin, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.rfind('|');
        books[bookCount].id = stoi(line.substr(0, pos1));
        books[bookCount].title = line.substr(pos1 + 1, pos2 - pos1 - 1);
        books[bookCount].author = line.substr(pos2 + 1);
        bookCount++;
    }
    fin.close();
}

void viewBooks() {
    for (int i = 0; i < bookCount; i++) {
        cout << "ID: " << books[i].id
             << " | Title: " << books[i].title
             << " | Author: " << books[i].author << "\n";
    }
}
