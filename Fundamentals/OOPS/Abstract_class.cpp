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
      virtual float Area() = 0; // Pure virtual function is declared as follows.
};


class Rectangle: public Shape {
   private:
      int width;
      int height;
   public:
      // Function to set width.
      void setWidth(int w) {width = w;}
      // Function to set height.
      void setHeight(int h) {height = h;}

      float Area() { 
         return float(width * height); 
      }
};

class Triangle: public Shape {
   private:
      int width;
      int height;
   public:
      // Function to set width.
      void setWidth(int w) {width = w;}
      // Function to set height.
      void setHeight(int h) {height = h;}

      float Area() { 
         return float(width * height)/2; 
      }
};

class Circle: public Shape {
   private:
      int radius;
   public:
      // Function to set width.
      void setRadius(int r) {radius = r;}
      float Area() { 
         return 3.14*float(radius*radius);
      }
};

int main() {
  Rectangle R;
  Triangle T;
  Circle C;

  R.setWidth(5);
  R.setHeight(10);

  T.setWidth(15);
  T.setHeight(7);

  C.setRadius(5);

  cout << "The area of the rectangle is: " << R.Area() << endl;
  cout << "The area of the triangle is: " << T.Area() << endl;
  cout << "The area of the circle is: " << C.Area() << endl;
}