/*The word polymorphism means having many forms.
* In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.
*/


/* This program also gives an example about function overriding
*  Function overriding occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.
*/
   
  
#include <bits/stdc++.h>
using namespace std;
  
class base
{
public:
    virtual void print ()
    { cout<< "print base class" <<endl; }
   
    void show ()
    { cout<< "show base class" <<endl; }
};
   
class derived:public base
{
public:
    void print () 
//print () is already virtual function in derived class, we could also declared as virtual void print () explicitly
    { cout<< "print derived class" <<endl; }
   
    void show ()
    { cout<< "show derived class" <<endl; }
};
  
//main function
int main() 
{
    base *bptr;
    derived d;
    bptr = &d;
       
    //virtual function, binded at runtime (Runtime polymorphism)
    bptr->print(); 
       
    // Non-virtual function, binded at compile time
    bptr->show(); 
  
    return 0;
} 


/*This program gives the output as:-
print derived class
show base class
*/
