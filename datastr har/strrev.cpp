// C++ program to reverse a string using recursion 
# include <iostream>
using namespace std; 
  
/* Function to print reverse of the passed string */
void reverse(char *str) 
{ 
   if (*str) 
   { 
       reverse(str+1); 
       cout << *str; 
   } 
} 
  
/* Driver program to test above function */
int main() 
{ 
   char a[] = "Geeks for Geeks"; 
   reverse(a); 
   return 0; 
} 

