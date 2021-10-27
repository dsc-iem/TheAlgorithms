/*
* Data Abstraction is defined as the process of reducing the object
* to its essence so that only the necessary characteristics are exposed to the users.
* Abstraction defines an object in terms of its
* properties (attributes), behavior (methods), and interfaces (means of communicating with other objects).
*/


#include <iostream>
using namespace std;
  
class implementAbstraction
{
    private:
        int a, b;
  
    public:
      
        // method to set values of 
        // private members
        void set(int x, int y)
        {
            a = x;
            b = y;
        }
          
        void display()
        {
            cout<<"a = " <<a << endl;
            cout<<"b = " << b << endl;
        }
};
  
int main() 
{
    implementAbstraction obj;
    obj.set(10, 20);
    obj.display();
    return 0;
}


/*this program gives the output as 
  a=10
  b=20
*/
