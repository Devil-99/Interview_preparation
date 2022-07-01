#include <bits/stdc++.h>
using namespace std;

class Employee {
protected:
    string Name,Company;
    int Age;
public:
// manually made constructor
    Employee(string name,string company,int age)
    {
        Name=name;
        Company=company;
        Age=age;
    }
     void work(){ cout<<Name<<" is Searching Email"<<endl;}
    void print()
    {
        cout<<"Name is- "<<Name<<endl;
        cout<<"Company is- "<<Company<<endl;
        cout<<"Age is- "<<Age<<endl;
    }
};

// derivation is private in default
class Developer :public Employee{
public:
    string Language;
    // as parent class has no default constructor so we have to create our own constructor for developer class also
    Developer(string name,string company,int age,string language)
        : Employee(name,company,age)
    {
        Language=language;
    }
    void work(){ cout<<Name<<" is coding in "<<Language<<endl;}
};

class Teacher :public Employee{
public:
    string Subject;
    Teacher(string name,string company,int age,string subject)
        : Employee(name,company,age)
    {
        Subject=subject;
    }
    void work(){ cout<<Name<<" is tecahing "<<Subject<<endl;}

};

int main() {
    Employee emp = Employee("Souvik","GS",22);
    emp.work();

    Developer d = Developer("Shreejeeb","Infosys",23,"Python");
    d.work();

    Teacher t= Teacher("Dhiman Mondal","JGEC",48,"Computer Networks");
    t.work();

    return 0;
}