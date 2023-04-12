// Poly = Multiple, Morph = forms.
// It is a feature of OOP where we can have mutiple forms of same function with same name but different characteristics.

// We can't achieve polymorphism just by changing the return type. Change in argument is necessary.

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

    return 0;
}