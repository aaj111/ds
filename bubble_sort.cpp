#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class DoublyList{
    public:
    Node* head;

    DoublyList()
    {
        head = NULL;
    }
    void insertEnd(int data)
    {
        Node* node = new Node(data);
        if(head == NULL)
        {
            head = node;
            return;
        }
        Node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }

    void BubbleSort()
    {
        if(!head) return;
        bool swapped;
        Node * ptr;

        do{
            swapped = false;
            ptr = head;

            while(ptr->next!=NULL)
            {
                if(ptr->data>ptr->next->data)
                {
                    //swapping
                    int temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;
                    swapped = true;
                }
                ptr = ptr->next;
            }
        }
        while(swapped);
    }
    void display()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    DoublyList dl;
    dl.insertEnd(5);
    dl.insertEnd(15);
    dl.insertEnd(65);
    dl.insertEnd(35);
    dl.insertEnd(25);
    dl.insertEnd(45);

    cout<<"Originaal List: ";
    dl.display();

    dl.BubbleSort();

    cout<<"Sorted List: ";
    dl.display();
}
