//Program 3: WAP to reverse a user entered string using recursion.

#include<iostream>
#include<conio.h>
using namespace std;

void rev_string(char A[], int i)
{
	if(A[i]!='\0')
	{
		rev_string(A,i+1);
		cout<<A[i];
	}
}

void rev(char A[], int i, int size)
{
	if(i<=(size/2))
	{
		swap(A[i],A[size-i]);
		rev(A,i+1,size);
	}
}

int main()
{
	int size=0;
	char A[100];
	cout<<"\nEnter any string: ";
	cin.getline(A,100);
	while(A[size]!='\0'){
		size++;
	}
	cout<<"\nReverse string: ";
	rev(A,0,size-1);
	cout<<A;
	getch();
	return 0;
}

