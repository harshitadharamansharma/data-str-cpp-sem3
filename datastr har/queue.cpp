// Program to implement Queue using Linked List

# include <iostream>
using namespace std;

struct node
{
 int info;
 node *next;
}*front, *newptr, *save, *ptr, *rear;

node *createnewnode ( int n )
{
 ptr = new node;
 ptr -> info =n;
 ptr -> next = NULL;
 return ptr;  
}

void insert ( node *np )
{
 if( front == NULL )
 front = rear = np;
 
 else
 {
  rear -> next = np;
  rear = np;
 }
}

void display ( node *np )
{
 cout << " \n\t\t\t The Queue is : \n\t\t\t ";
 while( np != NULL )
 {
  cout << np -> info << "--> ";
  np = np -> next;
 }
 cout << " \n\n ";
}

void delnode ()
{
 if( front == NULL )
 cout << " \n\t\t\t UNDERFLOW \n\t\t\t ";
 
 else
 {
  ptr = front;
  front = front -> next;
  delete ptr; 
 }
 
}

int main()
{
 front = rear = NULL; 
 
 int data, n;
 char ch = 'y';
 
 cout << " \n\t\t\t Enter the number of nodes to inserted \n\t\t\t ";
 cin >> n;
 cout << " \n\t\t\t Enter the values of nodes \n\t\t\t ";
 for( int i = 0; i < n; i++ )
 {
  cout << " \n\t\t\t ";
  cin >> data;
  newptr = createnewnode ( data );
  insert ( newptr );
 }  
 
 display ( front );
 
 cout << " \n\t\t\t To delete first node press 'y' \n\t\t\t ";
 cin >> ch;
 
 if( ch == 'y' || ch == 'Y' )
 delnode();
 
 display ( front );

 return 0;
}  
 
