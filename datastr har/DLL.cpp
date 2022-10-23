// Doubly Linked List Implmentation

# include <iostream>
using namespace std;

template < class T >
class node
{
 public :
 T data ;
 node *next, *prev;
 node( T element, node *ptr1 = 0, node *ptr2 = 0)
 {
  data = element;
  next = ptr1;
  prev = ptr2;
 }
};

template < class T >
class DLL
{
 private:
 node <T> *head, *tail;
 
 public:
 DLL()
 {
  head = tail = 0;
 }
 
 void addHead( T element );
 void addTail( T element );
 void display();
 void deleteHead();
 void deleteTail();
 void search( T element );
 void reverse();                                        
};

template < class T >
void DLL <T> :: addHead( T element )
{
 node <T> *p = new node <T> (element);
 
 if( head == 0 )
 head = tail = p;
 
 else
 {
  p -> next = head;
  head -> prev = p;
  head = p;
 }
}

template < class T >
void DLL <T> :: addTail( T element )
{
 node <T> *p = new node <T> (element);
 if( tail == 0)
 head = tail = p;
 
 else
 {
  tail -> next = p;
  p -> prev = tail;
  tail = p;
 }

}

template < class T >
void DLL <T> :: display()
{
 if( head == 0)
 cout << "\n\t\t\t List is Empty \n\t\t\t ";
 
 else 
 {
  cout << " \n\t\t\t Now the list is : \n\t\t\t ";
  node <T> *temp = head;
  while( temp != 0 )
  {
   cout << temp -> data << " <-- "; 
   temp = temp -> next;
  }
 }
}


template < class T >
void DLL <T> :: deleteTail()
{
 if( tail == 0)
 cout << "\n\t\t\t List is Empty \n\t\t\t";
 
 else if( head == tail )
 {
  delete head;
  head = tail = 0;
 }
 
 else
 {
  node <T> *temp = tail;
  tail = tail -> prev;
  tail -> next  = 0;
  delete temp;
 }
}

template < class T >
void DLL <T> :: deleteHead()
{
 if( head == 0 )
 cout << "\n\t\t\t List is Empty\n\t\t\t";
 
 else
 {
  node <T> *temp = head;
  head = head -> next;
  head -> prev = 0;
  delete temp;
  
  if( head == 0 )
  tail = 0;
 }
}

template < class T >
void DLL <T> :: search( T element )
{
 int i = 0, flag = 0;
 if( head == 0)
 cout << "\n\t\t\t List is Empty \n\t\t\t";
 
 node <T> *temp = head;
 while( temp -> next != NULL )
 {
  i++;
  if( temp -> data == element )
  {
   flag = 1;
   break;
  }
  temp = temp -> next;
 } 

 if( flag == 1)
 cout << " \n\t\t\t Element " << element << " is found at " << i << " position \n\t\t\t ";
  
 else
 cout << " \n\t\t\t Element is not found \n\t\t\t ";
}


template < class T >
void DLL <T> :: reverse()
{
 if( head == NULL )
 cout << " \n\t\t\t List is empty \n\t\t\t ";
 
 else if( head == tail )
 cout << " \n\t\t\t Only one node \n\t\t\t ";
 
 
  node <T> *temp = NULL, *current;
  current = head;
  while( current != NULL )
  {
   temp = current -> next;
   current -> next = current -> prev;
   current -> prev = temp;
   current = temp;
  }
  
  temp = head;
  head = tail;
  tail = temp;
}

int main()
{
 int choice;
 char ch = 'y';
 
 DLL <int> l;
 
 int element,n;
 cout << " \n\t\t\t ****** INSERTION BEGINS ****** \n\t\t\t ";
 cout << " \n\t\t\t Enter the number of elements to be inserted \n\t\t\t ";
 cin >> n;
 cout << " \n\t\t\t Enter the values \n\t\t\t";
 for( int i = 0; i < n; i++ )
 {
  cout << " \n\t\t\t ";
  cin >> element;
  l.addHead(element);
 }
 
 l.display();
 
 cout << " \n\n\t\t\t MENU TO PERFORM OPERATIONS ON LIST \n\t\t\t ";
 cout << " \n\t\t\t 1. Add At Head \n\t\t\t ";
 cout << " \n\t\t\t 2. Add At Tail \n\t\t\t ";
 cout << " \n\t\t\t 3. Delete Head \n\t\t\t ";
 cout << " \n\t\t\t 4. Delete Tail \n\t\t\t ";
 cout << " \n\t\t\t 5. Reverse List \n\t\t\t ";
 cout << " \n\t\t\t 6. Search Element \n\t\t\t ";
 
 do
 {
  cout << " \n\t\t\t Enter Choice (1-6) \n\t\t\t ";
  cin >> choice;
  switch(choice)
  {
   case 1 : 
   cout << " \n\t\t\t Enter the value to be inserted at head \n\t\t\t ";
   cin >> element;
   l.addHead (element);
   l.display();
   break;
  
   case 2 :
   cout << " \n\t\t\t Enter the value to be inserted at tail \n\t\t\t ";
   cin >> element;
   l.addTail (element);
   l.display();
   break;
  
   case 3 :
   cout << " \n\t\t\t Deleting Head element \n\t\t\t ";
   l.deleteHead();
   l.display();
   break;
  
   case 4 :
   cout << " \n\t\t\t Deleting Tail element \n\t\t\t ";
   l.deleteTail();
   l.display();
   break;
  
   case 5 :
   cout << " \n\t\t\t Reversing the list \n\t\t\t ";
   l.reverse();
   l.display();
   break;
  
   case 6 :
   cout << " \n\t\t\t Enter the element to be searched \n\t\t\t ";
   cin >> element;
   l.search(element);
   break;
  
   default :
   cout << " \n\t\t\t Wrong Choice \n\t\t\t ";
  }
 
  cout << " \n\n\t\t\t To perform more operations press 'y' \n\t\t\t ";
  cin >> ch;
 
 }while( ch == 'y' || ch == 'Y' );
    
 cout << " \n\n ";   
 return 0;
}    
 
 
  
   
       

