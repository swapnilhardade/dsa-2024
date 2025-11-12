#include <iostream>
#include <string>
using namespace std;

// Structure for Student
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
        cout << "Enter Name: ";
        cin.ignore(); // to clear newline character from buffer
        getline(cin, students[i].name);
        cout << "Enter CGPA: ";
        cin >> students[i].cgpa;
    }
}

// Function to display student records
void displayRecords(Student* students, int n) {
    cout << "\nStudent Records:\n";
    cout << "----------------------------------------\n";
    cout << "ID\tName\t\tCGPA\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << students[i].id << "\t" << students[i].name << "\t\t" << students[i].cgpa << endl;
    }
    cout << "----------------------------------------\n";
}

// Function to sort by ID using Bubble Sort
void bubbleSort(Student* students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    cout << "\nRecords sorted by ID using Bubble Sort.\n";
}

// Function to sort by ID using Insertion Sort
void insertionSort(Student* students, int n) {
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].id > key.id) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
    cout << "\nRecords sorted by ID using Insertion Sort.\n";
}

int main() {
    int n = 5;
    Student* students = new Student[n]; // Dynamic memory allocation

    insertRecords(students, n);

    int choice;
    cout << "\nChoose Sorting Method:\n";
    cout << "1. Bubble Sort\n2. Insertion Sort\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
        bubbleSort(students, n);
    else if (choice == 2)
        insertionSort(students, n);
    else
        cout << "\nInvalid choice!\n";

    displayRecords(students, n);

    delete[] students; // Free allocated memory
    return 0;
}
