#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertBST(Node* root,int val)
{
    if(root == NULL)
    return new Node(val);
    
    if(val<root->data)
    root->left = insertBST(root->left,val);
    
    if(val>root->data)
    root->right = insertBST(root->right,val);
    
    return root;
}
bool searchBST(Node* root,int key)
{
    if(root == NULL)
    {
        cout<<"Tree empty\n";
        return false;
    }
    if(root->data == key)
    return true;
    if(key<root->data)
    {
        return searchBST(root->left,key);
    }
    if(key>root->data)
    {
        return searchBST(root->right,key);
    }
}
Node* findMin(Node* root)
{
    Node* temp = root;
    while(temp&& temp->left !=NULL)
    temp = temp->left;
    
    return temp;
}
Node* deleteBST(Node* root, int key)
{
 if(root == NULL)
 return root;
 if(key<root->data)
 {
     root->left = deleteBST(root->left,key);
 }
 else if(key>root->data)
 {
    root->right = deleteBST(root->right,key);
 }
 else
 {
     //case 1:no child
     if(root->left == NULL && root->right == NULL)
     {
         delete root;
         return NULL;
     }
     //case 2: one child
     else if(root->left == NULL)
     {
         Node* temp = root->right;
         delete root;
         return temp;
     }
     else if(root->right == NULL)
     {
         Node* temp = root->left;
         delete root;
         return temp;
     }
     //case 3:two children
     else
     {
         Node* temp = findMin(root->right);
         root->data = temp->data;
         root->right = deleteBST(root->right,temp->data);
     }
 }
 return root;
}
void levelOrder(Node* root)
{
    if(root == NULL)
    {
        cout<<"Tree is empty";
        return;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout<<curr->data;
        if(curr->left)
        q.push(curr->left);
        if(curr->right)
        q.push(curr->right);
    }
    cout<<endl;
}
int main() {
    Node* root = NULL;
    int choice, key;

    while (true) {
        cout << "\n------ BST MENU ------\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find/Search\n";
        cout << "4. Show (Level-order)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            root = insertBST(root, key);
            break;

        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            root = deleteBST(root, key);
            break;

        case 3:
            cout << "Enter key to find: ";
            cin >> key;
            if (searchBST(root, key))
                cout << "Key FOUND!\n";
            else
                cout << "Key NOT FOUND!\n";
            break;

        case 4:
            cout << "BST Level Order: ";
            levelOrder(root);
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
