#include <iostream>
#include <fstream>
#include <string>
#include "member.h"

using namespace std;

struct Member {
    int id;
    string name;
    Member* next;
};

Member* head = nullptr;

void addMemberToFile() {
    ofstream fout("members.txt", ios::app);
    Member* newMember = new Member;
    cout << "Enter Member ID: ";
    cin >> newMember->id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, newMember->name);
    fout << newMember->id << "|" << newMember->name << "\n";
    fout.close();
    newMember->next = head;
    head = newMember;
    cout << "Member added!\n";
}

void loadMembersFromFile() {
    ifstream fin("members.txt");
    string line;

    while (getline(fin, line)) {
        size_t pos = line.find('|');
        Member* newMember = new Member;
        newMember->id = stoi(line.substr(0, pos));
        newMember->name = line.substr(pos + 1);
        newMember->next = head;
        head = newMember;
    }
    fin.close();
}

void viewMembers() {
    Member* temp = head;
    while (temp) {
        cout << "ID: " << temp->id << " | Name: " << temp->name << "\n";
        temp = temp->next;
    }
}
