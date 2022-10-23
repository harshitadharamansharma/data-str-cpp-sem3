// Implementing stack using pointers

#include <iostream>
#include <process.h>
using namespace std;

struct node
{
 int data;
 node *next;
}*top, *newptr, *save, *ptr;

node *newnode( int n )
{
 ptr  = new node;
 ptr -> data = n;
 ptr -> next = NULL;
 return ptr;
}

void push( node* np )
{
 if( top == NULL )
 top = np;
 
 else
 {
  save = top;
  top = np;
  np -> next = save;
 }
}

void display( node* np )
{
 while( np != NULL )
 {
  cout << np -> data << " -> ";
  np = np -> next;
 }
 cout << " \n ";
}

void pop()
{
 if( top == NULL )
 cout << " \n\t\t\t UNDERFLOW \n\t\t\t ";
 
 else
 {
  ptr = top;
  top = top -> next;
  delete ptr;
 }
}

int main()
{
 top = NULL;
 int info;
 char = 'y';
 while( ch == 'y' || ch == 'Y' )
 { 
  cout << " \n\t\t\t Enter the data for new node \n\t\t\t";
  cin >> info;
  newptr = newnode(info);
  if( newptr == NULL )
  {
   cout << " \n\t\t\t Cannot create new node!!! Aborting \n\t\t\t ";
   exit(0);
  }
  push( newptr );
  cout << " \n\t\t\t Press Y to enter more nodes, N to exit \n\t\t\t ";
  cin >> ch;
 }
 
 do
 {
  cout << " \n\t\t\t The Stack now is : \n\t\t\t ";
  display(top);
  cout << " \n\t\t\t want to pop an element(y/n) \n\t\t\t ";
  cin >> ch;
  if( ch == 'y' || ch == 'Y' )
  pop();
 }while( ch == 'y' || ch == 'Y' );
 
 return 0; 
 }
}

