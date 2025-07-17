#include <iostream>
#include <fstream>
#include <queue>
#include "issue.h"

using namespace std;

queue<int> issueQ;

void issueBook() {
    int memberId;
    cout << "Enter Member ID to issue book: ";
    cin >> memberId;
    issueQ.push(memberId);

    ofstream fout("issue.txt", ios::app);
    fout << memberId << "\n";
    fout.close();

    cout << "Book issue queued!\n";
}

void loadIssueQueue() {
    ifstream fin("issue.txt");
    int id;
    while (fin >> id) issueQ.push(id);
    fin.close();
}

void viewIssueQueue() {
    queue<int> temp = issueQ;
    while (!temp.empty()) {
        cout << "Member ID in queue: " << temp.front() << "\n";
        temp.pop();
    }
}
