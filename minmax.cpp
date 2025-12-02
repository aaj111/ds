// Write a Program to create a Binary Tree Search and Find Minimum/Maximum in BST 
#include<iostream>
using namespace std;
class Node
{
  public:
  int data;
  Node* left;
  Node* right;
  
  Node(int data){
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
    {
        root->left = insertBST(root->left,val);
    }
    else
    {
        root->right = insertBST(root->right,val);
    }
    return root;
}
bool searchBST(Node* root,int key)
{
    if(root == NULL) return false;
    if(root->data == key)return true;
    
    if(key<root->data)
    {
         return searchBST(root->left,key);
    }
    else return searchBST(root->right,key);
}
int findMin(Node* root)
{
    if(root == NULL)
    return -1;
    
    Node* temp = root;
    while(temp->left!=NULL)
    temp = temp->left;
    
    return temp->data;
}
int findMax(Node* root)
{
    if(root == NULL)
    return -1;
    
    Node* temp = root;
    while(temp->right!=NULL)
    temp = temp->right;
    
    return temp->data;
}
int main()
{
    Node* root = NULL;
     root = insertBST(root,5);
     root = insertBST(root,15);
     root = insertBST(root,25);
     root = insertBST(root,35);
     root = insertBST(root,45);
    
    cout<<findMin(root);
    cout<<endl;
    cout<<findMax(root);
    if(searchBST(root,35))
    {
        cout<<"Found!!";
    }
}
