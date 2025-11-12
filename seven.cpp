#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of the circular queue

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert element into circular queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full! Cannot insert " << element << endl;
            return;
        }
        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout << "Inserted: " << element << endl;
    }

    // Delete element from circular queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to delete." << endl;
            return;
        }

        cout << "Deleted: " << items[front] << endl;

        if (front == rear) {
            // Queue has only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Circular Queue Elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Insert (Enqueue)\n";
        cout << "2. Delete (Dequeue)\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            cq.enqueue(value);
            break;

        case 2:
            cq.dequeue();
            break;

        case 3:
            cq.display();
            break;

        case 4:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
