/*
* Encapsulation in Java is a mechanism of wrapping the data (variables) and
* code acting on the data (methods) together as a single unit.
* In encapsulation, the variables of a class will be hidden from other classes,
* and can be accessed only through the methods of their current class.
*/


//This program finds the area of a rectangle while showing encapsulation for calculating the area

#include <iostream>
using namespace std;

class Rectangle {
  public:
    // Variables required for area calculation
    int length;
    int breadth;

    // Constructor to initialize variables
    Rectangle(int len, int brth) : length(len), breadth(brth) {}

    // Function to calculate area
    int getArea() {
      return length * breadth;
    }
};

int main() {
  // Create object of Rectangle class
  Rectangle rect(8, 6);

  // Call getArea() function
  cout << "Area = " << rect.getArea();

  return 0;
}


/*This program gives the output as:-
Area = 48
*/
