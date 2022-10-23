// Program to implement Array Based Queue

#include <iostream>
using namespace std;

const int size = 50;
int queue[ size ], front = -1, rear = -1;

int remove( int queue[] )
{
 int ret;
 
 if( front == -1 )
 return -1;
 
 else
 {
  ret = queue[front];
 
  if( front == rear )
  front = rear = -1;
  
  else front ++;
 }
 return ret;
}

int insert( int queue[], int ele )
{
 if( rear == size )
 return -1;
 
 else if( rear == -1 )
 {
  front = rear = 0;
  queue[rear] = ele;
 }
 
 else
 {
  rear++;
  queue[rear] = ele;
 }
 return 0;
}

void display( int queue[], int front, int rear )
{
 if( front == -1 )
 return;
 
 cout << " \n\t\t\t Now the queue is : \n\t\t\t ";
 for( int i = front; i < rear; i++ )
 cout << queue[ i ] << " <-";
 cout << queue[ rear ] << endl;   
}

int main()
{
 int item, res, n;
 char ch = 'y';
 cout << " \n\t\t\t Enter the number of items to be inserted ( < 50 ) \n\t\t\t ";
 cin >> n;
 cout << " \n\t\t\t Enter the values \n\t\t\t ";
 for( int i = 0; i < n; i++ )
 {
  cout << " \n\t\t\t ";
  cin >> item;
  res = insert( queue, item );
 }
 display( queue, front, rear );
     
 cout << " \n\t\t\t To delete first element press 'y' \n\t\t\t ";
 cin >> ch;
 
 if( ch == 'y' || ch == 'Y' )
 res = remove( queue );
 
 cout << " \n\t\t\t Element deleted is " << res << " \n\t\t\t ";
 display( queue, front, rear );
 
 cout << " \n\n ";
 return 0;
} 

