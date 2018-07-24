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
    bool search(node* root, int val);
    void inOrder(node*);
    inline node* getRoot () { return root; }
    node* deleteNode(node* root, int val);
  node* getMinNode(node*);
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

//go left, process the node(print value), go right
void
BST::inOrder(node* root) 
{
  if (root == NULL) 
    return;
  inOrder(root->left);
  std::cout<<root->data<<" ";
  inOrder(root->right);
}    

bool
BST::search(node* root, int val)
{
  if (root == NULL)
    return false;
  if (root->data == val) {
    return true;
  } else if (val > root->data) {
    return search(root->right, val);
  } else
    return search(root->left, val);
}

//1. is the tree is empty return NULL
//2. If the node to be deleted has zero or one children, assign the childern to the parent of the node to be deleted
//3. if the node has 2 childern then get the lowest value node from the right subtree and replace it with the node to be deleted and delete the smallest node in the right subtree
node*
BST::deleteNode(node* root, int val)
{
  if (root == NULL) { // tree is empty
    return NULL;
  }
  if (val > root->data) {
    root->right = deleteNode(root->right, val);
  } else if (val < root->data) {
    root->left = deleteNode(root->left, val);   
  } else {
    if (root->left == NULL) {
      return root->right;    
    } else if (root->left == NULL) {
      return root->right;
    } else {
      node* temp = getMinNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }       
  }
  return root;
}

node*
BST::getMinNode(node* root)
{
  while (root->left != NULL)
    root= root->left;

  return root;    
}    

int main()
{
  std::cout<<"start\n";
  BST* tree = new BST;
  //get the null root here in the starting
  node* root = tree->getRoot();
  root = tree->addNode(root,5);
  tree->addNode(root,8);
  tree->addNode(root, 3);
  tree->addNode(root, 4);
  tree->addNode(root, 2);
  tree->addNode(root, 15);
  tree->addNode(root, 6);
  tree->addNode(root, 7);
  tree->inOrder(root);
  std::cout<<"\n";
  std::cout<<tree->search(root, 4)<<"\n";
  std::cout<<tree->search(root, 6)<<"\n";
  root = tree->deleteNode(root, 7);
  tree->inOrder(root);
  return 0;
}
