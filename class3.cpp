#include<iostream>
using namespace std;

class Add
{
      private :
             int a , b , c; 
      public  :
             void setData(int n1,int n2,int n3)
             {
                   a=n1;
                   b=n2;
                   c=n3;

             }  
             void Getdata()
             {
                cout<<"Enter the value of A"<<endl;
                cin>>a;
                cout<<"Enter the value of B"<<endl;
                cin>>b;
                cout<<"Enter the value of C"<<endl;
                cin>>c;
             }
             void dispaly()
             {
                cout<<"The sum of Three num is"<<endl;
                cout<<a+b+c<<endl;
             }     
};
int main()
{
    Add obj1;
    obj1.Getdata();
    obj1.dispaly();
}