// An abstract class is a class that is designed to be specifically used as a base class.
// An abstract class contains at least one pure virtual function.
// You declare a pure virtual function by using a pure specifier (= 0) in the declaration of a virtual member function in the class declaration.

/* A function declaration cannot have both a pure specifier and a definition.
struct A {
  virtual void g() { } = 0;
};
*/
// Abstract class is used to use same characteristic with different classes and functions hiding the backend of the abstract class

#include <iostream>
using namespace std;

class Shape {
   public:
      virtual int Area() = 0; // Pure virtual function is declared as follows.

      // Function to set width.
      void setWidth(int w) {width = w;}
      // Function to set height.
      void setHeight(int h) {height = h;}
   
   protected:
      int width;
      int height;
};

// A rectangle is a shape; it inherits shape.
class Rectangle: public Shape {
   public:
      int Area() { 
         return (width * height); 
      }
};
// A triangle is a shape too; it inherits shape.
class Triangle: public Shape {
   public:
      int Area() { 
         return (width * height)/2; 
      }
};

int main() {
  Rectangle R;
  Triangle T;

  R.setWidth(5);
  R.setHeight(10);

  T.setWidth(20);
  T.setHeight(8);

  cout << "The area of the rectangle is: " << R.Area() << endl;
  cout << "The area of the triangle is: " << T.Area() << endl;
}