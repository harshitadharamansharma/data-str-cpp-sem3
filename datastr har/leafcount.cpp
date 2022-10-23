// Program to count no. of leaf nodes in Binary Search Tree 

#include <iostream> 
using namespace std;
  
/* A binary tree node has data, pointer to left child  
   and a pointer to right child */
struct Node  
{ 
 int data; 
 Node* left; 
 Node* right; 
}; 
  
/* Function to get the count of leaf nodes in a binary tree*/
unsigned int getLeafCount( Node* node ) 
{ 
 if( node == NULL )        
  return 0; 
 if( node->left == NULL && node->right == NULL )       
  return 1;             
 else 
  return getLeafCount(node->left)+ 
         getLeafCount(node->right);       
} 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
Node* newNode( int data )  
{ 
 Node* node = new Node; 
 node->data = data; 
 node->left = NULL; 
 node->right = NULL; 
    
  return( node ); 
} 
  
/*Driver program to test above functions*/  
int main() 
{ 
  /*create a tree*/  
  Node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);     
    
  /*get leaf count of the above created tree*/
  cout << " \n\t\t\t Leaf count of the tree is " << getLeafCount(root) << " \n\t\t\t "; 
    
  cout << "\n\n"; 
  return 0; 
} 
