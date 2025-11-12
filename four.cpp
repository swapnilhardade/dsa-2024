#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

void insertRecords(Student* s, int n) {
    cout << "Enter details of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Enter ID: ";
        cin >> s[i].id;
        cin.ignore();  // Clear input buffer
        cout << "Enter Name: ";
        getline(cin, s[i].name);
        cout << "Enter CGPA: ";
        cin >> s[i].cgpa;
    }
}

void displayRecords(Student* s, int n) {
    cout << "\n--- Student Records ---\n";
    cout << "ID\tName\t\tCGPA\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].id << "\t" << s[i].name << "\t\t" << s[i].cgpa << endl;
    }
}

void bubbleSortByCGPA(Student* s, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].cgpa > s[j + 1].cgpa) {
                // Swap records
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    cout << "\nRecords sorted by CGPA (ascending order).\n";
}

int main() {
    int n = 5;
    Student* students = new Student[n]; // Dynamic memory allocation

    insertRecords(students, n);

    cout << "\nBefore Sorting:";
    displayRecords(students, n);

    bubbleSortByCGPA(students, n);

    cout << "\nAfter Sorting:";
    displayRecords(students, n);

    delete[] students; // Free memory
    return 0;
}
