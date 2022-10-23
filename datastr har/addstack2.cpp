// Program to add two large integers using stack

#include <iostream>
#include <conio.h>
#include <cstring>

class stack
{
   public:
       int top;
       int size;
       int * a;
       stack(int s = 10)
       {
           size = s ;
           top  = -1;
           a    = new int[size];
       }

       void push (int element);
       int pop ();
       void clear ();
       bool isEmpty ()
       {
           if (top == -1)
              return true;
           else
              return false;
       }
       void display()
       {
           int i;
           for (i = top; i >= 0; i--)
              cout << a[i];
       }
      void evaluate(stack s2);
};

int stack :: pop()
{
   if (top == -1)
   {
   	cout << "empty";
   	return -1;
   }
   else
   {
      int element = a[top];
      top --;
      return element;
   }
}

void stack :: push(int element)
{
    if(top == (size-1))
      cout << "\n OVERFLOW";
    else
    {
       top ++;
       a[top] = element;
    }
}

void stack :: clear()
{
    delete []a;
}

void stack :: evaluate (stack s2)
{
   int carry =0, sum;
   stack s3;
   while (!isEmpty() || !s2.isEmpty())
   {
       if (!isEmpty() && !s2.isEmpty())
       {
           int n1 = pop();
           int n2 = s2.pop();
           sum = n1+n2+carry;

           if (sum <=9)
           {
              carry =0;
              s3.push(sum);
           }
           else
           {
                carry = sum/10;
                sum = sum%10;
                s3.push(sum);
           }
       }

       else if (!isEmpty())
       {
           int n1 = pop();
           sum = n1+carry;
           if (sum <= 9)
           {
                carry = 0;
                s3.push(sum);
           }
           else
           {
                carry = sum/10;
                sum = sum%10;
                s3.push(sum);
           }
       }
   }
   if(carry!=0)
   	s3.push(carry);
   s3.display();
}

int main()
{
   int i =0;
   stack s, t;
   string s1, s2;
   cout << "\n Enter the first integer";
   cin  >> s1;
   cout << "\n Enter the second integer";
   cin  >> s2;

   int n = s1.length();
   while (i<n)
   {
      s.push (s1[i] - 48);
      i++;
   }
   i = 0;
   n = s2.length();
   while (i<n)
   {
      t.push (s2[i] - 48);
      i++;
   }

   s.evaluate (t);
   cout << endl;
   getch();
   return 0;
}
