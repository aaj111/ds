#include <iostream>
using namespace std;

// Node structure for Linked List
class Node {
public:
    string callerName;
    Node* next;

    Node(string name) {
        callerName = name;
        next = NULL;
    }
};

// Queue implemented using Linked List
class CallQueue {
private:
    Node* front;
    Node* rear;

public:
    CallQueue() {
        front = rear = NULL;
    }

    // Enqueue operation (new call arrives)
    void enqueue(string name) {
        Node* newNode = new Node(name);

        if (rear == NULL) {  // Empty queue
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Call from " << name << " received and added to queue.\n";
    }

    // Dequeue operation (agent handles a call)
    void dequeue() {
        if (front == NULL) {
            cout << "No calls waiting. System is idle.\n";
            return;
        }

        Node* temp = front;
        cout << "Agent is now assisting: " << front->callerName << endl;

        front = front->next;

        if (front == NULL)   // Queue became empty
            rear = NULL;

        delete temp;
    }

    // Display waiting calls
    void display() {
        if (front == NULL) {
            cout << "No calls in queue.\n";
            return;
        }

        cout << "Calls waiting in queue: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->callerName << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    CallQueue q;
    int choice;
    string name;

    do {
        cout << "\n--- Call Center Queue System ---\n";
        cout << "1. New Incoming Call (Enqueue)\n";
        cout << "2. Agent Answers Next Call (Dequeue)\n";
        cout << "3. Display Waiting Calls\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter caller name: ";
                cin >> name;
                q.enqueue(name);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
