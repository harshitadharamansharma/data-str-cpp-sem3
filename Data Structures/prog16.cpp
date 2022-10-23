#include<iostream>
using namespace std;

int partition(int A[], int low, int high);
void inp_arr(int A[],int size)
{
	for(int i=0; i<size; i++)
	{
		cin>>A[i];
	}
}

void display(int A[], int size)
{
	for(int i=0; i<size; i++)
	{
		cout<<A[i]<<" ";
	}
}

void bubble_sort( int A[], int size)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-i-1; j++)
		{
			if( A[j]>A[j+1])
				swap(A[j],A[j+1]);
		}
	}
}

void insertion_sort( int A[], int size)
{
	int temp,j;
	for(int i=1; i<size; i++)
	{
		temp=A[i];
		for( j=i-1; temp<A[j] && j>=0; j--)
		{
			A[j+1]=A[j];
		}
		A[j+1]=temp;
	}
}

void selection_sort( int A[], int size)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if( A[i]>A[j])
				swap(A[i],A[j]);
		}
	}
}

void merge_sort( int A[], int size)
{

}

void quick_sort( int A[], int low, int high)
{
	int pi;
	if( low<high)
	{
		pi=partition(A,low,high);
		quick_sort(A,low,pi-1);
		quick_sort(A,pi+1,high);
	}
}

int partition(int A[], int low, int high)
{
	int pivot=A[high];
	int i=low-1, j;
	for( j=low; j<high; j++)
	{
		if(A[j]<=pivot)
		{
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[high]);
	return i+1;
}

int lsearch_ite(int A[], int num, int size)
{
	for(int i=0; i<size; i++)
	{
		if(A[i]==num)
			return i+1;
	}
	return 0;
 }
int lsearch_rec(int A[],int num,int index, int size)
{
	if(index<size)
	{
		if(A[index]==num)
			return index+1;
		else
			lsearch_rec(A,num,index+1,size);
	}
	else
		return 0;
}

int bsearch_ite(int A[], int num, int size)
{
	int beg=0, end=size;
	int mid;
	while(beg<end)
	{
		mid=(beg+end)/2;
		if(A[mid]==num)
			return mid+1;
		else if(A[mid]>num)
			end=mid-1;
		else
			beg=mid+1;
	}
	return 0;
}

int bsearch_rec(int A[], int num, int beg, int end)
{
	int mid=(beg+end)/2;
	if(beg>end)
		return 0;
	else if(A[mid]==num)
		return mid+1;
	else if(A[mid]>num)
		return bsearch_rec(A,num,beg,mid-1);
	else
		return bsearch_rec(A,num,mid+1, end);
}

int main()
{
	int num,num2, size, found;
	char ch;
	
	cout<<"\nEnter total number of values: ";
	cin>>size;
	int A[size], B[size];
	cout<<"\nEnter elements:-\n";
	inp_arr(A,size);
	for(int i=0;i<size;i++)
	{
		B[i]=A[i];
	}
	do
	{
		for(int i=0;i<size;i++)
		{
			A[i]=B[i];
		}
		system("cls");
		display(A,size);
		cout<<"\n***********MENU****************";
		cout<<"\n1. Bubble sort.";
		cout<<"\n2. Insertion sort.";
		cout<<"\n3. Selection sort.";
		cout<<"\n4. Merge sort.";
		cout<<"\n5. Quick sort.";
		cout<<"\n6. Linear serach.";
		cout<<"\n7. Binary search.";
		cout<<"\n8. Exit.";
		cout<<"\n\nEnter your choice: ";
		cin>>num;	
		
		switch(num)
		{
			case 1: bubble_sort(A,size);
					display(A,size);
					break;
					
			case 2: insertion_sort(A,size);
					display(A,size);
					break;
					
			case 3: selection_sort(A,size);
					display(A,size);
					break;
					
			case 4: merge_sort(A,size);
					display(A,size);
					break;
					
			case 5: quick_sort(A,0,size-1);
					display(A,size);
					break;
					
			case 6: system("cls");
					cout<<"\nEnter number to be searched: ";
					cin>>num2;
					cout<<"\n1. Search using iteration.";
					cout<<"\n2. Search using recursion.";
					cout<<"\nEnter your choice: ";
					cin>>num;

					if(num==1)
					{
						if(found=lsearch_ite(A,num2,size))
							cout<<"\nNumber found at "<<found<<" position.";
						else
							cout<<"\nNot found.";
					}
					else 
					{
						if(found=lsearch_rec(A,num2,0,size))
							cout<<"\nNumber found at "<<found<<" position.";
						else
							cout<<"\nNot found.";
					}
					break;
					
			case 7: system("cls");
					cout<<"\nEnter number to be searched: ";
					cin>>num2;
					cout<<"\n1. Search using iteration.";
					cout<<"\n2. Search using recursion.";
					cout<<"\nEnter your choice: ";
					cin>>num;
				
					if(num==1)
					{
						if(found=bsearch_ite(A,num2,size))
							cout<<"\nNumber found at "<<found<<" position.";
						else
							cout<<"\nNot found.";
					}
					else 
					{
						if(found=bsearch_rec(A,num2,0,size-1))
							cout<<"\nNumber found at "<<found<<" position.";
						else
							cout<<"\nNot found.";
					}
					break;
					
			case 8: cout<<"EXITING...";
					exit(100);
					break;
			default: cout<<"\nWrong input!!!";
					break;
		}
		
		
		cout<<"\nShow Menu again(y/n): ";
		cin>>ch;
		
	}while(ch=='y');
	return 0;
}
