// Implementing Stack using Array

#include <iostream>
#include <cstdlib>
using namespace std;

const int size = 50;

int push( int array[], int top, int n )
{
 if( top == size-1 )
  return -1;
 
 else
 {
  ++top;
  array[top] = n;
 } 
 return 0;
}
  
int pop( int array[], int &top )
{
 int ret;
 
 if( top == -1 )
  return -1;
 
 else
 {
  ret = array[top];
  top--;
 }
 return ret;                                        
}
 
void display( int array[10], int top )
{
 if( top == -1 )
  return;
  
 cout << array[top] << "<--" << "\n\t\t";
 for( int i = top; i >= 0; i-- )
 cout << array[i] << " ";    
}

int main()
{
 int array[size], res, n;
 int top = -1;
 char ch = 'y';
 
 while( ch == 'y' || ch == 'Y' )
 {
   cout << "\n\t\t\tEnter the element to be inserted in stack\n\t\t\t";
   cin >> n;
   res = push( array, top, n );
   if( res == -1 )
   {
    cout << "\n\t\t\tStack Overflow\n\n";
    exit(0);
   }
   cout << "\n\t\t\tNow the Stack is \n\t\t\t";
   display( array, top ); 
   cout << "\n\t\t\tTo enter more elements press 'y'\n\t\t\t";
   cin >> ch;
  }
  
  ch = 'y';
  
  while( ch == 'y' || ch == 'Y' )
  { 
   cout << "\n\t\t\tNow Deletion\n\t\t\t"; 
   res = pop( array, top );
   if( res == -1 )
   {
    cout << "\n\t\t\tStack Underflow\n\n";
    exit(0);
   }
   cout << "\n\t\t\tNow the Stack is \n\t\t\t";
   display( array, top );
   cout << "\n\t\t\tTo delete more elements press 'y' \n\t\t\t";
   cin >> ch;
  }
 
 cout << " \n\t\t\t ";
 return 0;  
} 
