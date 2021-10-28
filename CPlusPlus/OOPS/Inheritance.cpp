/*
* Inheritance in Java is a concept that acquires the properties from one class to other classes;
* for example, the relationship between father and son.
* In Java, a class can inherit attributes and methods from another class.
* The class that inherits the properties is known as the sub-class or the child class.
*/


// In the following program An object of sub class child has all data members and member functions of base class parent

        
#include <bits/stdc++.h>
using namespace std;
 
//Base class
class Parent
{
    public:
      int id_p;
};
  
// Sub class inheriting from Base Class(Parent)
class Child : public Parent
{
    public:
      int id_c;
};
 
//main function
int main()
   {
      
        Child obj1;
          
        
        obj1.id_c = 7;
        obj1.id_p = 91;
        cout << "Child id is " <<  obj1.id_c << endl;
        cout << "Parent id is " <<  obj1.id_p << endl;
         
        return 0;
   }


/*This program gives the output as :-
  Child id is 7
  Parent id is 91
*/
