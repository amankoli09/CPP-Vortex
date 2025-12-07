#include <iostream>
using namespace std;

class Student 
{
   private:
        int rollno;
        char name[50];
    public:
        void setdata() 
        {
            cout<<"Enter Roll Number: "<<endl;
            cin>>rollno;
            cout<<"Enter Name: "<<endl;
            cin>>name;
        }
        void displaydata() 
        {
            cout<<"Roll Number: "<<rollno<<endl;
            cout<<"Name: "<<name<<endl;
        }
};
int main() 
{
    Student obj;
    obj.setdata();
    obj.displaydata();
    return 0;
}