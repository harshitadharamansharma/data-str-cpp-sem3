/*Program 4: Perform the following Stack operations using Linked List implementation.
a) Push
b) Pop
c) Clear*/

#include<iostream>
#include<stdlib.h>
#include<process.h>
using namespace std;

struct node
{
	int data;
	node*next;
}*top,*ptr,*save,*rear,*ptr1;

node*create(int n)
{
	ptr1=new node;
	ptr1->data=n;
	ptr1->next=NULL;
	return ptr1;
}

void push(node* np)
{
	node* t;
	if(top==NULL){
		top=np;
	}
	else
	{
		t=top;
		np->next=top;
		top=np;
	}
}	

void pop()
{
	node*t;
	if(top==NULL)
	{
		cout<<"underflow ";
	}
	else
	{
		t=top;
		top=top->next;
	}
	delete t;
}

void display(node * np)
{
	while(np!=NULL)
	{
		cout<<np->data<<endl;
		np=np->next;
	}
}

int main()
{
	int choice;
	char chii;
	int ch;
	char choo;
	int inf;
	top=NULL;
	char ch1;

	do{
		cout<<"Enter your choice"<<endl;
		cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter the inf of new node ";         
					cin>>inf;                         
					ptr=create(inf);
					if(ptr!=NULL)
					{
						cout<<endl<<"node created successfully ";
					}
					else
						cout<<"Error creating node "<<endl; 	               
					push(ptr);
					break;

			case 2: pop();            
                	break;

			case 3: cout<<"The link list is "<<endl; 
					display(top);
            		break;

			case 4:exit(0);

			default: cout<<"wrong choice";
					 break;
        }
		cout<<endl<<"do you want to continue ";
		cin>>ch1;	

	}while((ch1=='y')||(ch1=='Y'));

	return 0;
}

