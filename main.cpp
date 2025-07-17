#include <iostream>
#include "book.h"
#include "member.h"
#include "issue.h"
#include "return.h"

using namespace std;

int main() {
    loadBooksFromFile();     
    loadMembersFromFile();   
    loadIssueQueue();        
    loadReturnStack();       
    int choice;
    do {
        cout << "\n====== Library System ======\n";
        cout << "1. Add Book\n2. View Books\n";
        cout << "3. Add Member\n4. View Members\n";
        cout << "5. Issue Book\n6. View Issue Queue\n";
        cout << "7. Return Book\n8. View Return History\n";
        cout << "0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBookToFile(); break;
            case 2: viewBooks(); break;
            case 3: addMemberToFile(); break;
            case 4: viewMembers(); break;
            case 5: issueBook(); break;
            case 6: viewIssueQueue(); break;
            case 7: returnBook(); break;
            case 8: viewReturnHistory(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
