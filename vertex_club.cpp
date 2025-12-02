#include<iostream>
using namespace std;

class Node
{
    public:
    int prn;
    string name;
    Node* next;

    Node(int p,string n)
    {
        prn = p;
        name = n;
        next = NULL;
    }
};

class VertexClub
{
    public:
    Node* head;

    VertexClub()
    {
        head = NULL;
    }

    void addPresident(int prn,string name)
    {
        Node* newNode = new Node(prn,name);
        newNode->next = head;
        head = newNode;
    }

    void addSecretary(int prn,string name)
    {
        Node* newNode = new Node(prn,name);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addMember(int prn,string name,int afterPRN)
    {
        Node* temp = head;

        while(temp!=NULL && temp->prn !=afterPRN)
        {
            temp = temp->next;
        }
        if(temp == NULL)
        {
            cout<<"PRN not found\n";
            return;
        }
        Node* newNode = new Node(prn,name);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deletePresident()
    {
        if(head == NULL)
        {
            cout<<"List empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteSecretary()
    {
        if(head == NULL)
        {
            cout<<"List empty\n";
            return;
        }
        if(head->next ==NULL)
        {
            delete head;
            head->next = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next!=NULL)
        {
            temp= temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void deleteMember(int prn)
    {
        if(head == NULL)
        {
            cout<<"List empty\n";
            return;
        }
        Node* temp = head;

        while(temp->next!=NULL && temp->next->prn!=prn)
        temp = temp->next;

        if(temp->next == NULL)
        {
            cout<<"Member not found\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
    int countMembers()
    {
        int count = 0;
        Node* temp = head;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void display()
    {
        if(head == NULL)
        {
            cout<<"List empty\n";
            return;
        }
        Node* temp = head;
        cout<<"Vertext club members:\n";
        while(temp!=NULL)
        {
            cout<<"PRN: "<<temp->prn<<" | Name: "<<temp->name<<endl;
            temp = temp->next;
        }
    }

    void concatenate(VertexClub& other)
    {
        if(head == NULL)
        {
            head = other.head;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = other.head;
    }
    void search(int prn)
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            if(temp->prn = prn)
            {
                cout<<"Member found "<<temp->name<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"Member not found\n";
    }
};
int main() {
    VertexClub divA, divB;

    // Adding sample members for Division A
    divA.addPresident(101, "Amit");
    divA.addSecretary(105, "Riya");
    divA.addMember(103, "Neha", 101);
    divA.addMember(104, "Karan", 103);

    cout << "\n--- Division A ---";
    divA.display();
    cout << "Total Members: " << divA.countMembers() << endl;

    // Adding sample members for Division B
    divB.addPresident(201, "Siya");
    divB.addSecretary(205, "Arjun");
    divB.addMember(203, "Meera", 201);

    cout << "\n--- Division B ---";
    divB.display();

    // Concatenate lists
    cout << "\nConcatenating A + B ...\n";
    divA.concatenate(divB);

    cout << "\n--- Combined Club ---";
    divA.display();

    // Sorting
    // divA.sort();
    // cout << "\n--- Sorted by PRN ---";
    // divA.display();

    // Search
    cout << "\nSearching for PRN 104:\n";
    divA.search(104);

    // Reverse
    // cout << "\nReversed List:\n";
    // divA.reverse();
    // divA.display();

    return 0;
}