// Program to Search and Insert in a Binary Search Tree

#include <iostream>
using namespace std;

struct node
{
 int key;
 node *left, *right;
};

node *newnode( int item )
{
 node *temp = new node;
 temp -> key = item;
 temp -> left = temp -> right = NULL;
 return temp;
} 

node *insert( node *ptr, int key )
{
 if( ptr == NULL )
 return newnode ( key );
 
 if( key < ptr -> key )
 ptr -> left = insert ( ptr -> left, key );
 
 else if( key > ptr -> key )
 ptr -> right = insert ( ptr -> right, key );
 
 return ptr;
}

node *preorder( node *root )
{
 if( root != NULL )
 {
  cout << root -> key << " ";
  preorder( root -> left );
  postorder( root -> right );
 }
}

node *inorder( node *root )
{
 if( root != NULL )
 {
  inorder( root -> left );
  cout << root -> key << "  ";
  inorder( root -> right );
 }
}

node *postorder( node *root )
{
 if( root != NULL )
 {
  postorder( root -> left );
  postorder( root -> right );
  cout << root -> key << " ";
 }
}

node *mirrorImage( node *root )
{
 node *ptr;
 
 if( root != NULL )
 {
  mirrorImage( root -> left );
  mirrorImage( root -> right);
  ptr -> left = ptr -> right;
  root -> right = ptr;
 }
}

node *search( node *root, int key )
{
 if( root == NULL || root -> key == key )
 return root;
 
 if( root -> key < key )
 return search( root -> right, key );
 
 return search( root -> left, key );
}  

void deleteMerge( node *root )
{

}

void deleteCopy( node *root )
{

}

node *deleteTree( node *root )
{
 if( root != NULL )
 {
  deleteTree( root -> left );
  deleteTree( root -> right );
  delete root;
 }
}

int Height(struct node *tree)
{
 int leftheight, rightheight;

 if(tree==NULL)
 return 0;

 else
 {
  leftheight = Height(tree–>left);
  rightheight = Height(tree–>right);
 
  if(leftheight > rightheight)
  return (leftheight + 1);
  
  else
  return (rightheight + 1);
 }
}

int totalNodes(struct node *tree)
{
 if(tree==NULL)
 return 0;
 
 else
 return(totalNodes(tree–>left) + totalNodes(tree–>right) + 1);
}

int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    // print inoder traversal of the BST 
    inorder(root); 
   
    return 0; 
} 
 
