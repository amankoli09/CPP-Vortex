#include<iostream>
using namespace std;

class Animal
{
        private : 
                int no_Legs;
                int no_Horns;
        public :
                void setLegs(int l)    // setters 
                {
                    l=no_Legs;
                }        
                void setHorns(int h)   // setters
                {
                    h=no_Horns;
                }
                void showLegs()      // geters
                {
                    cout<<"enter the no legs : "<<endl;
                    cin>>no_Legs;
                    cout<<"the no of legs are : "<<no_Legs<<endl;
                }        
                void showHorns()        // geterss
                {
                    cout<<"enter the no Horns : "<<endl;
                    cin>>no_Horns;
                    cout<<"the no of horns  are : "<<no_Horns<<endl;
                }        
};
int main()
{
    Animal obj1,obj2;

   // obj1.setLegs();
    obj1.showLegs();

    cout<<endl;

    obj2.showHorns();

}