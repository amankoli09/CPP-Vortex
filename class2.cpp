#include <iostream>
using namespace std;

class Swaping
{
    private:
            int a,b,temp;
    public:
            void setdata()
            {
                cout<<"Enter first number: "<<endl;
                cin>>a;
                cout<<"Enter second number: "<<endl;
                cin>>b;
            }
            void swapdata()
            {
                temp=a;
                a=b;
                b=temp;
            }
            void beforeswapdisplay()
            {
                cout<<"Before Swapping the numbers are: "<<"a = "<<a<<" b = "<<b<<endl;
            }
            void afterswapdisplay()
            {
                cout<<"After Swapping the numbers are: "<<"a = "<<a<<" b = "<<b<<endl;
            }
            void display()
            {
                beforeswapdisplay();
                afterswapdisplay();
            }

};
int main()
{
    Swaping obj1;
    obj1.setdata();
    obj1.beforeswapdisplay();
    obj1.swapdata();
    obj1.afterswapdisplay();
    return 0;
}