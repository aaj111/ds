#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = NULL;
    }
};

class PatientQueue {
public:
    Node* front;
    Node* rear;

    PatientQueue() {
        front = rear = NULL;
    }

    // Add patient (enqueue)
    void enqueue(string name) {
        Node* newNode = new Node(name);

        if (rear == NULL) {
            front = rear = newNode;
            cout << name << " checked in!\n";
            return;
        }
        rear->next = newNode;
        rear = newNode;
        cout << name << " checked in!\n";
    }

    // Assign patient (dequeue)
    void dequeue() {
        if (front == NULL) {
            cout << "No patients waiting!\n";
            return;
        }

        Node* temp = front;
        cout << "Assigning " << temp->name << " to doctor...\n";

        front = front->next;
        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    // Display waiting list
    void display() {
        if (front == NULL) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "Patients waiting:\n";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PatientQueue pq;

    // Simulating patient check-ins
    pq.enqueue("Rohan");
    pq.enqueue("Sneha");
    pq.enqueue("Amit");

    cout << "\nCurrent Waiting List:\n";
    pq.display();

    // Assign first patient
    cout << "\nDoctor is available now...\n";
    pq.dequeue();

    cout << "\nUpdated Waiting List:\n";
    pq.display();

    // Assign another patient
    cout << "\nDoctor is available again...\n";
    pq.dequeue();

    cout << "\nFinal Waiting List:\n";
    pq.display();

    return 0;
}
