// Example program
#include <iostream>
#include <string>

class node
{
    public:
        int data;
        node* left;
        node* right;
        node(int val) : data(val), left(NULL), right(NULL) {}
};    
    
class BST
{
    private:
        node* root;
    public:
        BST() : root(NULL) {}
        node* addNode(node* root, int val);
        void inOrder(node*);
        inline node* getRoot () { return root; }
};

//1.if root is null tree is empty add node to root
//2. if root is not NULL, add node based on the value
node* 
BST::addNode(node* root, int val) 
{
    if (root == NULL) {
        node* temp = new node(val);
        return temp;
    } else if (val > root->data) {
        root->right = addNode(root->right, val);       
    } else {
        root->left = addNode(root->left, val);    
    }    
    return root;
}

void
BST::inOrder(node* root) 
{
    if (root == NULL) 
        return;
    inOrder(root->left);
    std::cout<<root->data<<" ";
    inOrder(root->right);
}    

int main()
{
    BST* tree = new BST;
    //get the null root here in the starting
    node* root = tree->getRoot();
    root = tree->addNode(root,5);
    tree->addNode(root,8);
    tree->addNode(root, 1);
    tree->addNode(root, 4);
    tree->inOrder(root);
    return 0;
}
