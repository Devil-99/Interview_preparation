// There are two types of constructor - 1.Default Constructor, 2.Parameterised Constructor

#include <bits/stdc++.h>
using namespace std;

// Deafult Constructor
class Teacher{
    public:
        Teacher()
        { cout<<"Default Constructor created"<<endl;}
};

class employee{
    // by default everything in a class is private.
public:
    string name,company;
    int age;

    // Parameterised constructor
    employee(string Name,string Company,int Age)
    {
        name=Name;
        company=Company;
        age=Age;
    }

    void print()
    {
        cout<<"Name is- "<<name<<endl;
        cout<<"Company is- "<<company<<endl;
        cout<<"Age is- "<<age<<endl;
    }
};

int main() {
    // if default constructor is used we have to manually give them input
    // employee emp1;
    // emp1.name="Souvik";
    // emp1.company="GS";
    // emp1.age=22;

    //if we use user name constructor
    employee emp1=employee("Souvik","GS",22);
    emp1.print();

    employee emp2=employee("Nilesh","Media",22);
    emp2.print();

    Teacher t;
    return 0;
}