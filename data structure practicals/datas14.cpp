/*Program 14: Write a menu driven program to implement the following operations in an ordered linked list:
a) Insertion
b) Deletion
c) Merging
*/
#include<iostream>
using namespace std;

class llnode											
{
	public:
		int info;
		llnode *next;
		
		llnode( int a, llnode *ptr)
		{
			info=a;
			next=ptr;
		}
		llnode(int a)
		{
			info=a;
			next='\0';
		}
		llnode()
		{
			next='\0';
		}	
};

class llist												 		
{
	llnode *head, *tail;
	public:
	llist()
	{
		head=tail='\0';
	}
	
	void insert_end( int x)
	{
		llnode *p;
		p= new llnode(x);
		
		if(head=='\0')
		{
			head=p;
			tail=p;
		}
		else
		{
			tail->next=p;
			tail=p;
		}
	}

	void insert_ordered( int x)
	{
		llnode *p, *q, *r;
		p= new llnode(x);
		q=head;
		
		if(head=='\0')
		{
			head=p;
			tail=p;
		}
		else if(x<head->info)
		{
			p->next=head;
			head=p;
		}
		else if(x>tail->info)
		{
			tail->next=p;
			tail=p;
		}
		else
		{
			while(q->info<x)
			{
				r=q;
				q=q->next;
			}
			r->next=p;
			p->next=q;
		}
	}
	
	void delete_beg()
	{
		llnode *p;
		p=head;
		if(head=='\0')
		{
			cout<<"\ncannot delete element as list is empty.";
		}
		else if(head==tail && head!='\0')
		{
			head='\0';
			tail='\0';
		}
		else
		{
			head=head->next;
			delete p;
		}
	}
	
	void delete_end()
	{
		llnode *p,*q,*r;
		p=head;
		q=tail;
		if(head=='\0')
		{
			cout<<"\ncannot delete element as list is empty.";
		}
		else if(head==tail && head!='\0')
		{
			head='\0';
			tail='\0';
		}
		else
		{
			while(p!=tail)
			{
				r=p;
				p=p->next;
			}
			tail=r;
			delete q;
		}
	}
	
	void dbef_pvalue( int pvalue)
	{
		llnode *p,*q,*r;
		r=head;
		
		if(head=='\0')
		{
			cout<<"\nNo element in list.";
		}
		else
		{
			while(r->info!=pvalue)
			{
				if(r->info!=pvalue && r->next=='\0')
				{
					cout<<"\nElement not found!!!";
					cout<<"\nExiting";
					exit(1);
				}			
				q=r;
				r=r->next;
			}
			if(r==head)
			{
				cout<<"\nNo element before "<<pvalue;
			}
			else if( q==head)
			{
				head=r;
				delete q;
			}
			else
			{
				p=head;
				while(p->next!=q)
				{
					p=p->next;
				}
				p->next=r;
				delete q;
			}
		}
	}
	
	void daft_pvalue( int pvalue)
	{
		llnode *p,*q,*r;
		q=head;
		
		if(head=='\0')
		{
			cout<<"\nNo element in list.";
		}
		else
		{
			while(q->info!=pvalue)
			{
				if(q->info!=pvalue && q->next=='\0')
				{
					cout<<"\nElement not found!!!";
					cout<<"\nExiting";
					exit(1);
				}
				r=q;
				q=q->next;
			}
			if(q==head)
			{
				if(head==tail)
				{
					cout<<"\nNo element after "<<pvalue;
				}
				else if(head->next==tail)
				{
					p=tail;
					tail=head;
					delete p;
				}
				else
				{
					p=head->next;
					r=p->next;
					head->next=r;
					delete p;
				}
			}
			else if( q==tail)
			{
				cout<<"\nNo element after "<<pvalue;
			}
			else
			{
				p=q->next;
				if(p==tail)
				{
					tail=q;
				}
				else
				{
					r=p->next;
					q->next=r;
				}
				delete p;
			}
		}
	}
	
	void dat_ppos( int ppos)
	{
		llnode *p,*q,*r;
		q=head;
		if(ppos<1)
		{
			cout<<"\nWrong input!!!";
		}
		else if(ppos==1)
		{
			if(head=='\0')
			{
				cout<<"\nCannot delete element as no element in list.";
			}
			else if( head==tail && head!='\0')
			{
				head='\0';
				tail='\0';
				delete q;
			}
			else
			{
				head=head->next;
				delete q;
			}	
		}
		else
		{
			for(int i=ppos; i>=2; i--)
			{
				if(q->next=='\0' && i!=2)
				{
					cout<<"\nWrong position!!";
					cout<<"\nExiting";
					exit(1);
				}	
				r=q;
				q=q->next;
			}
			if(q==tail)
			{
				tail=r;
				delete q;	
			}
			else
			{
				p=q->next;
				r->next=p;
				delete q;
			}
		
		}
	}
	
	llist merge(llist ob)
	{
		llist ob2;
		llnode *p, *q,*r;
		p=head;
		q=ob.head;
	
		while(p!='\0' && q!='\0')
		{
			if(p->info<q->info)
			{
				ob2.insert_end(p->info);
				p=p->next;
			}
			else if(p->info==q->info)
			{
				ob2.insert_end( p->info );
				p=p->next;
				q=q->next;
			}
			else
			{
				ob2.insert_end(q->info);
				q=q->next;
			}
		}
	
		if(p!='\0')
		{
			while(p!='\0')
			{
				ob2.insert_end(p->info);
				p=p->next;
			}	
		}
	
		else if( q!='\0')
		{
			while(q!='\0')
			{
				ob2.insert_end(q->info);
				q=q->next;
			}
			
		}
		return ob2;
	}
	
	void disp()
	{
		llnode *p;
		p=head;
		if(head=='\0')
		{
			cout<<"\nList is empty.";
		}
		else
		{
			cout<<"\nList: ";
			while(p!=tail)
			{
				cout<<p->info<<" ";
				p=p->next;
			}
			cout<<p->info;
		}	
	}
};

int main()
{
	int choice, num,num2;
	char ch;
	llist ob1, ob2, ob3;
	do
	{
		system("cls");
		cout<<"\n1. Insert element.";
		cout<<"\n2. Delete element.";
		cout<<"\n3. Merge two lists.";
		cout<<"\n4. Display list.";
		cout<<"\n5. Exit.";
		cout<<"\n\nEnter your choice: ";
		cin>>choice;
		
		system("cls");
		switch(choice)
		{
			case 1: cout<<"\nEnter value for new element: ";
					cin>>num;
					ob1.insert_ordered(num);
					break;
					
			case 2: cout<<"\n1. Delete element from beginning.";
					cout<<"\n2. Delete element from end.";
					cout<<"\n3. Delete element before a particaular value.";
					cout<<"\n4. Delete element after a particaular value.";
					cout<<"\n5. Delete element at a particular index value.";
					cout<<"\n\nEnter your choice: ";
					cin>>choice;
					
					switch(choice)
					{
						case 1: ob1.delete_beg();
								break;
						case 2:	ob1.delete_end();
								break;
						case 3: cout<<"\nEneter element before which you want to delete element: ";
								cin>>num2;
								ob1.dbef_pvalue(num2);
								break;
						case 4: cout<<"\nEneter element after which you want to delete element: ";
								cin>>num2;
								ob1.daft_pvalue(num2);
								break;
						case 5: cout<<"\nEnter position at which you want to delete element: ";
								cin>>num2;
								ob1.dat_ppos(num2);
								break;
						default:cout<<"\nWrong input";
								break;
					}
					break;
			
			case 3: cout<<"\nProvide another list(temporary list with insertion at end only):-\n";
					cout<<"\nEnter number of elements: ";
					cin>>num;
					cout<<"\nEnter elements:-\n";
					for(int i=0; i<num; i++)
					{
						cin>>num2;
						ob2.insert_end(num2);	
					}
					ob3=ob1.merge(ob2);
					ob3.disp();
					break;
				
			case 4: ob1.disp();
					break;
			case 5: cout<<"\nEXITING...";
					exit(100);
					
			default: cout<<"\nWrong input!!!";
					break;			
		}
		cout<<"\n\nEnter again(y/n): ";
		cin>>ch;
	}while(ch=='y');
	return 0;
}

