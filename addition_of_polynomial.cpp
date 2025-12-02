#include<iostream>
using namespace std;
class Node
{
    public:
    int coeff;
    int pow;
    Node* next;

    Node(int coeff,int pow)
    {
        this->coeff = coeff;
        this->pow = pow;
        this->next = NULL;
    }
};
class Polynomial
{
    public:
    Node *head;

    Polynomial()
    {
        head = NULL;
    }

    void insertTerm(int coeff,int pow)
    {
        Node* newNode = new Node(coeff,pow);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    static Polynomial add(Polynomial &p1,Polynomial &p2)
    {
        Polynomial result;
        Node *a = p1.head;
        Node *b = p2.head;

        while(a!= NULL && b!=NULL)
        {
            if(a->pow == b->pow)
            {
                result.insertTerm(a->coeff + b->coeff,a->pow);
                a = a->next;
                b = b->next;
            }
            else if(a->pow>b->pow)
            {
                result.insertTerm(a->coeff,a->pow);
                a = a->next;
            }
            else
            {
                result.insertTerm(b->coeff,b->pow);
                b = b->next;
            }
        }

            while(a!=NULL)
            {
                result.insertTerm(a->coeff,a->pow);
                a = a->next;
            }
            while(b!=NULL)
            {
                result.insertTerm(b->coeff,b->pow);
                b = b->next;
            }
        return result;
    }
    void display()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->coeff<< "x^" << temp->pow;
            if(temp->next != NULL)
            cout<<" + ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Polynomial p1,p2;
    p1.insertTerm(6,4);
    p1.insertTerm(5,3);
    p1.insertTerm(4,2);
    p1.insertTerm(2,1);

    p2.insertTerm(6,3);
    p2.insertTerm(3,1);
    p2.insertTerm(4,0);

    cout<<"Polynomial 1 is : ";
    p1.display();

    cout<<"Polynomial 2 is : ";
    p2.display();

    Polynomial sum = Polynomial::add(p1,p2);

    cout<<"Sum: ";
    sum.display();
}