#include <iostream>
#include <string>
using namespace std;

// Structure to store student information
struct Student {
    int id;
    string name;
    float cgpa;
};

// Function to insert student records
void insertRecords(Student* students, int n) {
    cout << "\nEnter details of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Enter ID: ";
        cin >> students[i].id;
        cin.ignore(); // clear input buffer
        cout << "Enter Name: ";
        getline(cin, students[i].name);
        cout << "Enter CGPA: ";
        cin >> students[i].cgpa;
    }
}

// Function to display all student records
void displayRecords(Student* students, int n) {
    cout << "\n--- Student Records ---\n";
    cout << "ID\tName\t\tCGPA\n";
    cout << "-------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << students[i].id << "\t" << students[i].name << "\t\t" << students[i].cgpa << endl;
    }
}

// Function to search a student by ID using Linear Search
void searchByID(Student* students, int n, int key) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].id == key) {
            cout << "\nRecord Found!\n";
            cout << "ID: " << students[i].id << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "CGPA: " << students[i].cgpa << "\n";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\nNo student found with ID " << key << ".\n";
}

int main() {
    int n = 5; // number of students
    Student* students = new Student[n]; // dynamic memory allocation

    insertRecords(students, n);
    displayRecords(students, n);

    int searchID;
    cout << "\nEnter ID to search: ";
    cin >> searchID;
    searchByID(students, n, searchID);

    delete[] students; // free allocated memory
    return 0;
}
