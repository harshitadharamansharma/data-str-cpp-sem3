// Program to implement diagonal matrix using 1-D array 

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <process>

template <class T> class diagonalMatrix
{
     public:
         diagonalMatrix (int size=10)
         {
             n = size;
             d = new T(n);
         }  // constructor
         ~diagonalMatrix()
         {
             delete []d;
         }  // destructor
         diagonalMatrix <T> & store (const T & x, int i, int j);
         T retrive (int i,int j) const;
     private:
         int n;
         T * d;
};   // class diagonalMatrix

template <class T> class lowerTrianglrMatrix
{
     public:
         lowerTrianglrMatrix (int size = 10)
         {
             n = size;
             t = new T (3 * n - 2);
         }  // constructor
         ~lowerTrianglrMatrix ()
         {
             delete [] t;
         }  // destructor
         lowerTrianglrMatrix <T> & store (const T & x, int i, int j);
         T retrive (int i, int j) const;
     private:
         int n;
         T * t;
};   // class lowerTrianglrMatrix

template <class T> class upprTrianglrMatrix
{
    public:
         upprTrianglrMatrix (int size = 10)
         {
             n = size;
             t = new T [n * (n-1) / 2];
         }
         ~upprTrianglrMatrix ()
         {
             delete [] t;
         }
         upprTrianglrMatrix <T> & store (const T & x, int i, int j);
         T retrive (int i, int j) const;
    private:
         int n;
         T * t;
};  // class upprTrianglrMatrix

template <class T> class symmetricMatrix
{
    public:
         symmetricMatrix (int size = 10)
         {
             n = size;
             t = new T [n * (n-1) / 2];
         }
         ~symmetricMatrix ()
         {
             delete [] t;
         }
         symmetricMatrix <T> & store (const T & x, int i, int j);
         T retrive (int i, int j) const;
    private:
         int n;
         T * t;
};  // class symmetricMatrix

template <class T> diagonalMatrix<T> & diagonalMatrix<T> :: store (const T & x,int i, int j)
{
    if (i<0 || i>=n || j<0 || j>=n)
        cout << "\n Out Of Bound";
    if (i != j && x != 0)
         cout << "\n Must be zero";
    if (i == j)
         d[i] = x;
    return * this;
}   // store diagonalMatrix

template <class T> T diagonalMatrix <T> :: retrive (int i, int j) const
{
    if (i<0 || j<0 || i>=n || j>=n )
         cout << "\nOut of bounds";
    if (i==j)
         return d[i];
    else
         return 0;
}   // retrive diagonalMatrix

template <class T> lowerTrianglrMatrix <T> & lowerTrianglrMatrix <T> :: store (const T & x, int i, int j)
{
    if (i<0 || j<0 || i>=n || j>=n )
         cout << "\nOut of bounds";
    if (i>=j)
         t [i * (i-1) / 2 + j - 1] = x;
    else
        if (x != 0)
            cout << "\n Must be zero";
    return * this;
}   // store lowerTrianglrMatrix

template <class T> T lowerTrianglrMatrix<T> :: retrive (int i, int j) const
{
     if (i<0 || j<0 || i>=n || j>=n )
         cout << "\nOut of bounds";
     if (i>=j)
         return t [i * (i-1) / 2 + j - 1];
      else
         return 0;
}   // retrive lowerTrianglrMatrix

template <class T> upprTrianglrMatrix<T> & upprTrianglrMatrix<T> :: store (const T & x, int i ,int j)
{
    if (i<0 || j<0 || i>=n || j>=n )
         cout << "\nOut of bounds";
    if (i<=j)
         t  [j * (j-1) / 2 + i - 1] = x;
    else
        if (x != 0)
            cout << "\n Must be zero";
    return * this;
}   // store upprTrianglrMatrix

template <class T> T upprTrianglrMatrix<T> :: retrive (int i, int j) const
{
    if (i<0 || j<0 || i>=n || j>=n )
         cout << "\nOut of bounds";
    if (i<=j)
        return t  [j * (j-1) / 2 + i - 1];
    else
        return 0;
}   // retrive upprTrianglrMatrix

template <class T> symmetricMatrix<T> & symmetricMatrix<T> :: store (const T & x, int i ,int j)
{
    if (i<0 || j<0 || i>=n || j>=n )
         cout << "\nOut of bounds";
    if (i<=j)
         t  [i * (i-1) / 2 + j - 1] = x;
    else
        if (x != t  [i * (i-1) / 2 + j - 1])
            cout << "\n Must be equal";
    return * this;
}   // store symmetricMatrix

template <class T> T symmetricMatrix<T> :: retrive (int i, int j) const
{
    if (i<0 || j<0 || i>=n || j>=n )
         cout << "\nOut of bounds";
    if (i<=j)
        return t  [j * (j-1) / 2 + i - 1];
    else
        return t  [i * (i-1) / 2 + j - 1];
}   // retrive symmetricMatrix

int main ()
{
    int a;
    int i;
    int j;
    int n =3;
    char choice;
    
    diagonalMatrix      <int> dm(3);
    lowerTrianglrMatrix <int> lm(3);
    upprTrianglrMatrix  <int> um(3);
    symmetricMatrix     <int> sm(3);

    cout << "\n MENU DRIVEN PROGRAM \n to implement the following sparse matrices";
    cout << "\n\n *******************************************";
    cout << "\n (a) diagonal matrix";
    cout << "\n (b) lower triangular matrix";
    cout << "\n (c) upper triangular matrix";
    cout << "\n (d) symmetric matrix";
    cout << "\n *******************************************";
    cout << "\n\t Enter your choice: \n";
    cin  >> choice;

    switch (choice)
    {
         case 'a' :{
                    cout << "\nEnter the elements of diagonal matrix \n";
  						  for (i=0; i<n; ++i)
   				     for (j=0; j<n; ++j)
   				     {
                          cout << "\n Enter the element at [" << i << "]["
                               << j << "] : " ;
      					     cin  >> a;
     					        dm.store (a,i,j);
     					  }

                    cout << "\nThe diagonal matrix is\n";
                    for (i=0; i<n; ++i)
                    {
                        for (j=0; j<n; ++j)
                        {
                             a = dm.retrive (i,j);
                             cout << a << setw(3);
                        }
                        cout << endl;
                    }
         	       }
                   break;

         case 'b' : {
                        cout << "\nEnter the elements of lower triangular matrix\n";
  						      for (i=0; i<n; ++i)
   				         for (j=0; j<n; ++j)
   				         {
                          cout << "\n Enter the element at [" << i << "]["
                               << j << "] : " ;
      					     cin  >> a;
     					        lm.store (a,i,j);
     					      }

                        cout << "\nThe the lower triangular matrix is\n";
                        for (i=0; i<n; ++i)
                        {
                            for (j=0; j<n; ++j)
                            {
                                 a = lm.retrive (i,j);
                                 cout << a << setw(3);
                            }
                            cout << endl;
                        }
                    }
                    break;

         case 'c' : {
                        cout << "\nEnter the elements of upper triangular matrix \n";
  						      for (i=0; i<n; ++i)
   				         for (j=0; j<n; ++j)
   				         {
                          cout << "\n Enter the element at [" << i << "]["
                               << j << "] : " ;
      					     cin  >> a;
     					        um.store (a,i,j);
     					      }

                        cout << "\nThe upper triangular matrix is\n";
                        for (i=0; i<n; ++i)
                        {
                            for (j=0; j<n; ++j)
                            {
                                 a = um.retrive (i,j);
                                 cout << a << setw(3);
                            }
                            cout << endl;
                        }
                    }
                    break;

         case 'd' : {
                       cout << "\nEnter the elements of symmetric matrix \n";
                       for (i=0; i<n; ++i)
                          for (j=0; j<n; ++j)
                          {
                               cout << "\n Enter the element at [" << i << "]["
                               << j << "] : " ;
      					          cin  >> a;
     					             sm.store (a,i,j);
     					        }  // for
                       cout << "\nThe symmetric matrix is\n";
                       for (i=0; i<n; ++i)
                       {
                           for (j=0; j<n; ++j)
                           {
                                a = sm.retrive (i,j);
                                cout << a << setw(3);
                           }
                           cout << endl;
                       }
                    }
                    break;

         default  : cerr << "\n\a Wrong choice selected";
                    exit (0);
    }

    getche();

    return 0;
}
