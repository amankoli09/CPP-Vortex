#include<iostream>
using namespace std;

class Fibo
{
    public :
        void fibonaci()
        {
             int a,b,f,n;
             a=0;
             b=1;

             cout<<"enter the number to get fibo"<<endl;
             cin>>n;
             cout<<a<<endl;
             cout<<b<<endl;
             for (int  i = 1; i < n; i++)
             {
               f=a+b;
               cout<<f<<endl;
               a=b;
               b=f;
             }
             
        }
};
int main()
{
    Fibo fib_o;
    fib_o.fibonaci();

}
