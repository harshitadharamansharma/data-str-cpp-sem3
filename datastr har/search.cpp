// Menu driven program for Linear Search and Binary Search.

#include <iostream>
using namespace std;

void linear( int arr[], int n, int x )
{
  int flag = 0, index;
  
  for( int i = 0; i < n; i++ )
  if( arr[i] == x )
  {
   flag = 1;
   index = i;
   break;
  }    
  
  if( flag == 1)
  cout << " \n\t\t\t Element found at position " << index + 1 << " \n\t\t\t ";
  
  else 
  cout << " \n\n\t\t\t Element " << x << " is not present in the array \n\t\t\t ";
  
  return;
}

int binary( int arr[], int l, int r, int x ) 
{
 while( l < r )
 {
  int m = l + (r - l) / 2;
  
  if( arr[m] == x )
   return m;
   
  if( arr[m] < x )
   l = m + 1;
  
  else 
   r = m - 1;
 }
 
 return -1;  
}

void print( int arr[], int n )
{
 cout << " \n\t\t\t Array entered is : \n\t\t\t ";
 for( int i = 0; i < n; i++ )
 cout << arr[i] << " ";
 return;
}

int main()
{
 int array[20];
 int i, j, k, n, x;
 char ch;
 
 cout << " \n\t\t\t Press a for Linear Search \n\t\t\t ";
 cout << " \n\t\t\t Press b for Binary Search \n\t\t\t "; 
 cout << " \n\t\t\t Enter Choice \n\t\t\t ";
 cin >> ch;
 
 if( ch == 'a' || ch == 'A' )                                                     // Linear Search
 {
  cout << " \n\t\t\t Linear Search\n\t\t\t ";
  cout << " \n\t\t\t Enter the number of elements in array \n\t\t\t ";
  cin >> n;  
  cout << " \n\t\t\t Enter the elements of array \n\t\t\t ";
  for( i = 0; i < n; i++){ cout << " \n\t\t\t "; cin >> array[i]; }
  
  print( array, n );
  
  cout << " \n\t\t\t Enter the element to be searched \n\t\t\t ";
  cin >> x;
  
  linear( array, n, x );
 }
 
 if( ch == 'b' || ch == 'B' )                                                    // Binary Search
 {
  int flag; 
  cout << " \n\t\t\t Binary Search \n\t\t\t ";
  cout << "\n\t\t\t Enter the number of elements in array \n\t\t\t ";
  cin >> n;
  cout << " \n\t\t\t Enter the elements of array in ascending order \n\t\t\t ";
  for( i = 0; i < n; i++ ){ cout << " \n\t\t\t "; cin >> array[i]; }
  
  print( array, n );
  
  cout << " \n\n\t\t\t Enter the element to be searched \n\t\t\t ";
  cin >> x;  
  
  flag = binary( array, 0, n-1, x );
  
  if( flag != -1 )
  cout << " \n\t\t\t Element " << x << " is found at " << flag + 1 << " position \n\t\t\t ";
  
  else
  cout << " \n\t\t\t Element " << x << " is not present in the array \n\t\t\t ";   
 }
 
 cout << " \n\n ";
 return 0;   
} 
