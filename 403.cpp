#include<iostream>
#include<vector>
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
static int idx = -1;
Node* buildTree(vector<int> preorder)
{
    idx++;
    
    if(preorder[idx] == -1)
    return NULL;
    
    Node* root = new Node(preorder[idx]);
    root->left  = buildTree(preorder);
    root->right  = buildTree(preorder);
    return root;
}
void preOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}
void inOrder(Node* root)
{
    if(root == NULL)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node* root)
{
    if(root == NULL)
    return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int countLeaf(Node*  root)
{
    if(root == NULL)
    return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;
  return countLeaf(root->left) + countLeaf(root->right);
}
Node* mirror(Node* root)
{
    if (root == NULL) 
        return NULL;

    // Recursively mirror children
    Node* leftMirror = mirror(root->left);
    Node* rightMirror = mirror(root->right);

    // Swap the children
    root->left = rightMirror;
    root->right = leftMirror;

    return root;
}
int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"Leaf Nodes : "<<countLeaf(root);
}
