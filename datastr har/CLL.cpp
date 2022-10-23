// Program to implement Circular Linked List

# include <iostream>
using namespace std;

struct node
{
 int data;
 node *next;
};

node *addEmpty( node *last, int data )
{
 if ( last != NULL )
  return last;
 
 node *temp = new node;
 temp -> data = data;
 last = temp;
 last -> next = last;

 return last;
}

node *addBegin( node *last, int data )
{
 if( last == NULL )
 return addEmpty( last, data );
 
 node *temp = new node;
 temp -> data = data;
 temp -> next = temp;
 return last;
}

node *addEnd( node *last, int data )
{
 if( last == NULL )
  return addEmpty( last, data );
  
 node *temp = new node;
 temp -> data = data;
 temp -> next = last -> next;
 last -> next = temp;
 last = temp;
  
 return last;
}

node *addAfter( node *last, int data, int item )
{
 if( last == NULL )
  return NULL;
 
 node *temp, *p;
 p = last -> next;
 
 do
 {
  if( p -> data == item )
  {
   temp = new node;
   temp -> data = data;
   temp -> next = p -> next;
   p -> next = temp;
   
   if( p == last )
   last = temp;
   return last;
  }
  p = p -> next;
 }while( p != last -> next);
 
 cout << " \n\t\t\t Item not present " << item << " \n\t\t\t ";
 return last;
}

void traverse( node *last)
{
 struct node *p;
 
 if( last == NULL )
 {
  cout << "\n\t\t\t List is empty \n\t\t\t ";
  return;
 }
 
 p = last -> next;
 
 do
 {
  cout << p -> data << "  ";
  p = p -> next;
 }while( p != last -> next );
}

int main()
{
 node *last = NULL;
 last = addEmpty( last, 6 );
 last = addBegin( last, 4 );
 last = addBegin( last, 2 );
 last = addEnd( last, 8 );
 last = addEnd( last, 12 );
 last = addAfter( last, 10, 8 );
 
 traverse( last );
 cout << " \n\n ";
 return 0;
} 
   
       

