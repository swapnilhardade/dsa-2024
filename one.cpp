#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

int main() {
    int n = 5, searchID, found = 0;
    Student* s = new Student[n];
    
    cout << "Enter 5 student records:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEnter ID: ";
        cin >> s[i].id;
        cout << "Enter Name: ";
        cin >> s[i].name;
        cout << "Enter CGPA: ";
        cin >> s[i].cgpa;
    }

    cout << "\nAll Student Records:\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].id << "\t" << s[i].name << "\t" << s[i].cgpa << endl;
    }

    cout << "\nEnter ID to search: ";
    cin >> searchID;
    for (int i = 0; i < n; i++) {
        if (s[i].id == searchID) {
            cout << "\nRecord Found:\n";
            cout << s[i].id << "\t" << s[i].name << "\t" << s[i].cgpa << endl;
            found = 1;
            break;
        }
    }
    if (!found) cout << "\nRecord not found!\n";

    delete[] s;
    return 0;
}
