#include <iostream>
#include <fstream>
#include <stack>
#include "return.h"

using namespace std;

stack<int> returnS;

void returnBook() {
    int memberId;
    cout << "Enter Member ID returning book: ";
    cin >> memberId;
    returnS.push(memberId);

    ofstream fout("returns.txt", ios::app);
    fout << memberId << "\n";
    fout.close();

    cout << "Return recorded.\n";
}

void loadReturnStack() {
    ifstream fin("returns.txt");
    int id;
    while (fin >> id) returnS.push(id);
    fin.close();
}

void viewReturnHistory() {
    stack<int> temp = returnS;
    while (!temp.empty()) {
        cout << "Returned by Member ID: " << temp.top() << "\n";
        temp.pop();
    }
}
