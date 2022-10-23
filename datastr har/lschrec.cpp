// Program for Linear Search Using Recursion

#include <iostream>
using namespace std;

int recsearch( int arr[], int l, int r, int x )
{
 if( r < l )
  return -1;
 
 if( arr[l] == x )
  return l;
 
 return recsearch( arr, l + 1, r, x );
}

int main()
{
 int arr[50], n, x, i;
 
 cout << "\n\t\t\t Linear Search\n\t\t\t";
 
 cout << "\n\t\t\tEnter the number of elements in array\n\t\t\t";
 cin >> n;
   
 cout << "\n\t\t\tEnter the elements of array";
 for( i = 0; i < n; i++){ cout << "\n\t\t\t"; cin >> arr[i]; }
  
 cout << "\n\t\t\tEnter the element to be searched\n\t\t\t";
 cin >> x;
 int index = recsearch ( arr, 0, n - 1, x );
 
 if( index != -1 )
 cout << "\n\t\t\t Element " << x << " is present at index " << index;
 
 else
 cout << "\n\t\t\t Element " << x << " is not present ";
 
 cout << "\n\n";
 return 0;
} 
     
