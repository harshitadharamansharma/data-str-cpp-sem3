/*Program 5. Perform the following Stack operations using Array implementation using Templates:
a)	Push
b)	Pop
c)	Clear*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
int t;

template<class T> 
 class Mystack{

      T *st;
      int tos;
      int size;
   public:   
      Mystack()
      {
       tos=-1;        
       st=new T[10];
       }
       Mystack(int n)
       {
       tos=-1;
       t=n;
       size=n;
        st=new T[n];
        }
        void set(int i){
             t=i;
             size=i;
            st=new T[i];
             }
      void push(T item);
      T pop();
      void show();
      };
template<class T>
 void Mystack<T>::push(T item)
 {
           if(tos>size-1)
          { cout<<"stack overflow"<<endl;
            return;
            }
          else
          {
              st[++tos]=item;
              }
}
template<class T>
T Mystack<T>::pop()
{
    if(tos<0)
   { cout<<"stack underflow "<<endl;
     ::t=-1;
     }
    else
  { 
          return st[tos--];
}
} 
template <class T>
void Mystack<T>::show()
{
     if(tos<0)
     {
     return;
              }
      else          
   {  
     for(int i=tos;i>=0;i--)
     cout<<st[i]<<endl;
}  }
  

int main()
{   float f;
int i;
char c;
    char ch1;
    int n,ch,ch2,item;
   float item1; 
   char item2; 
    cout<<"Enter the type of array "<<endl<<"1.int"<<endl<<"2.float"<<endl<<"3.character"<<endl;
    cin>>ch2;
    cout<<"enter the size  of stack"<<endl;
    cin>>n;
    Mystack<int> ob1(n);
    Mystack<float> ob2(n);
    Mystack<char> ob3(n);
    
    switch(ch2){
                case  1: 
                     for(int i=0;i<n;i++) 
                     {       cout<<"Enter element to pushed"<<endl;
                     cin>>item;
                             ob1.push(item);
                             
                     }
                     cout<<"The stack is "<<endl;
                     ob1.show();
                     break;
                case 2: 
                     for(int i=0;i<n;i++)
                     {cout<<"Enter element to pushed"<<endl;
                     cin>>item1;
                             ob2.push(item1);                
                             
                             }
                             cout<<"The stack is "<<endl;
                             ob2.show(); 
                     break;
                case 3:
                     for(int i=0;i<n;i++)
                     {
                     cout<<"Enter element to pushed"<<endl;
                     cin>>item2;
                     
                     ob3.push(item2);
                     
                     }
                     cout<<"The stack is "<<endl;
                     ob3.show();
                     break;
                default: cout<<"Enter genuine choice";
}
   
   do{
    cout<<"do you want to delete any element"<<"1.yes"<<"2.NO"<<endl;
    cin>>ch;
    switch(ch)
    {
      case 1:
             if(ch2==1)
             {
                  ob1.pop(); 
                  cout<<"The new stack is "<<endl;    
                  ob1.show();
                       }
              else if(ch2==2){
                   ob2.pop();
                   cout<<"The new stack is "<<endl;
                   ob2.show();
                   }  
                   else if(ch2==3)
                   {
                    ob3.pop();
                    cout<<"the new stack is "<<endl;
                    ob3.show();
                    }
                    break;
      case 2: cout<<"dont want to enter : exit";
                          exit(0);
                         break; 
      default: cout<<"wrong choice"<<endl;             
      }
      if(::t<0)
      break;
      else
     { cout<<"do you want to continue"<<endl;
      cin>>ch1;
      }
     }while(ch1=='Y'||ch1=='y');  
    getch();
    return 0;
}
