// Poly = Multiple, Morph = forms.
// It is a feature of OOP where we can have mutiple forms of same function with same name but different characteristics.

// We can't achieve polymorphism just by changing the return type. Change in argument is necessary.
// In JAVA, final method(method defined as final) can't be overridden.

#include <bits/stdc++.h>
using namespace std;

// Compile time Polymorphism / Method Overloading
class Calculation {
    public:
        void print(int x){
            cout<<"The number is "<<x<<endl;
        }

        void print(string s){
            cout<<"The name is "<<s<<endl;
        }

        void print(int x,int y){
            cout<<"The sum is "<<x+y<<endl;
        }
};

// Operator Overloading

class Complex {
    private:
        int real;
        int img;
    public:
        Complex(int r=0,int i=0){
            real=r;
            img=i;
        }

        void display(){
            cout<<real<<"+i"<<img<<endl;
        }

        Complex operator +(Complex c){
            Complex temp;
            temp.real= real+c.real;
            temp.img=img+c.img;
            return temp;
        }
};

// Runtime Polymorphism / Method Overriding requires virtual function.

class Parent {
    public:
        void show(){
            cout<<"Show parent class"<<endl;
        }
};

class Child : public Parent {
    public:
        void show(){
            cout<<"Show child class"<<endl;
        }
};

int main(){
    Calculation c;

    c.print(5);
    c.print("Souvik");
    c.print(5,8);

    Parent p;
    Child ch;
    p.show();
    ch.show();

    Complex c1(5,3), c2(10,5), c3;
    c3 = c1+c2;
    c3.display();

    return 0;
}