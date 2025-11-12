#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

// Function to sort students by ID (needed before binary search)
void sortStudents(Student* students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].id > students[j].id) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to display all records
void displayStudents(Student* students, int n) {
    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << students[i].id
             << " | Name: " << students[i].name
             << " | CGPA: " << students[i].cgpa << endl;
    }
}

// Binary search function
int binarySearch(Student* students, int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (students[mid].id == key)
            return mid;
        else if (students[mid].id < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n = 5;
    Student* students = new Student[n];  // Dynamic memory allocation

    cout << "Enter details of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEnter ID: ";
        cin >> students[i].id;
        cout << "Enter Name: ";
        cin.ignore(); 
        getline(cin, students[i].name);
        cout << "Enter CGPA: ";
        cin >> students[i].cgpa;
    }

    // Sort before performing binary search
    sortStudents(students, n);

    // Display all student records
    displayStudents(students, n);

    // Search by ID
    int searchID;
    cout << "\nEnter ID to search: ";
    cin >> searchID;

    int result = binarySearch(students, n, searchID);
    if (result != -1) {
        cout << "\nRecord Found:\n";
        cout << "ID: " << students[result].id
             << " | Name: " << students[result].name
             << " | CGPA: " << students[result].cgpa << endl;
    } else {
        cout << "\nRecord with ID " << searchID << " not found.\n";
    }

    delete[] students;  // Free dynamically allocated memory
    return 0;
}
