#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory freed with data "<<value<<endl;
    }
};
void print(Node *head)
{
    Node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertAtHead(Node* &head,Node* &tail, int data)
{
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(data);
            temp->next = head;
            head->prev = temp;
            head = temp;
    }
}
void insertAtTail(Node* &head,Node* &tail,int data)
{
    if(tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    if(position == 1)
    {
        insertAtHead(head,tail,data);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt<position-1)
    {
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL)
    {
        insertAtTail(head,tail,data);
        return;
    }
    Node* nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    nodetoinsert->prev = temp;
    temp->next = nodetoinsert;
}
int getlen(Node *head)
{
    int len = 0;
    Node *temp = head;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
}
void deleteNode(int position,Node* &head)
{
    if(position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while(cnt<position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 20);
    print(head);

    insertAtHead(head, tail, 30);
    print(head);

    insertAtTail(head,tail,55);
    print(head);

    insertAtTail(head,tail,65);
    print(head);

    insertAtPosition(head, tail, 1, 1);
    print(head);

    insertAtPosition(head, tail, 6, 61);
    print(head);

    insertAtPosition(head, tail, 7, 71);
    print(head);
    
    deleteNode(7,head);
    print(head);

    deleteNode(1,head);
    print(head);

}
