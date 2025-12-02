#include<iostream>
using namespace std;
class Node
{
    public:
    int price;
    Node* next;

    Node(int p)
    {
        price = p;
        next = NULL;
    }
};
class StockStack{
    public:
    Node* top;

    StockStack()
    {
        top = NULL;
    }
    void record(int price)
    {
        Node* newNode = new Node(price);
        newNode->next = top;
        top = newNode;
        cout<<"Recorded price: "<<price<<endl;
    }
    int removePrice()
    {
        if(isEmpty())
        {
            cout<<"No price to remove\n";
            return -1;
        }
        int removed = top->price;
        Node* temp = top;
        top = top->next;
        delete temp;


        return removed;
    }
    int latest()
    {
        if(isEmpty())
        {
            cout<<"No proves recorded";
            return -1;
        }
        return top->price;
    }
    bool isEmpty()
    {
        return (top==NULL);
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"No price to remove\n";
            return;
        }
      cout << "Stock Price History (Latest → Oldest):\n"; 
      Node* temp = top;
      while(temp!=NULL)
      {
        cout<<temp->price<<" ";
        temp = temp->next;
      }  
      cout<<endl;
    }
};

int main()
{
    StockStack s;
    s.record(150);
    s.record(155);
    s.record(160);
    s.record(165);

    
    cout << "\nLatest price: " << s.latest() << endl;

    cout << "\nRemoving latest price...\n";
    cout << "Removed: " << s.removePrice() << endl;

    cout << "\nLatest price now: " << s.latest() << endl;

    cout << "\nDisplaying all prices:\n";
    s.display();

}