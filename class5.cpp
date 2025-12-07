#include<iostream>
using namespace std;
 
class ADD 
{
   private :
            int a1;

   protected :
            int b1;

            public: 
                void getindata()
                {
                      cout<<"enter the first num:"<<endl;
                      cin>>a1;
                      cout<<"enter the second num:"<<endl;
                      cin>>b1;

                }
                // void putindata()
                // {
                //     cout<<" Enter first num is = "<< a1 <<endl;
                //     cout<<" Enter second num is = "<< b1 <<endl;
                // }
                void addData()
                {
                    cout<<"addition of enter two num is = "<<a1+b1<<endl;
                }

        
};
int main()
{
    ADD og;
    og.getindata();
    // og.putindata();
    og.addData();

}