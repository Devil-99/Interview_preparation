
// It is a feature of OOP where the child classes gets all the characteristics of the parent class.

#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
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

// these are the setters and getters for accessing the private variable
    void setName(string name){Name=name;}
    string getName(){return Name;}

    void setCompany(string company){Company=company;}
    string getCompany(){return Company;}

    void setAge(int age){ Age=(age>=18)?age:Age;}
    int getAge(){return Age;}
    
    void print()
    {
        cout<<"Name is- "<<Name<<endl;
        cout<<"Company is- "<<Company<<endl;
        cout<<"Age is- "<<Age<<endl;
    }
};

// derivation is private in default
class Developer : Employee{
private:
    string Language;
public:
    // as parent class has no default constructor so we have to create our own constructor for developer class also
    Developer(string name,string company,int age,string language)
        : Employee(name,company,age)
    {
        Language=language;
    }
    void BugFix(){ cout<<getName()<<" works in "<<Language<<endl;}
};

class Teacher :public Employee{
public:
    string Subject;
    Teacher(string name,string company,int age,string subject)
        : Employee(name,company,age)
    {
        Subject=subject;
    }
    void Lesson()
    {cout<< getName()<<" teaches "<<Subject;}
};

int main() {
    Employee e= Employee("Souvik","Amazon",23);
    e.print();
    
    Developer d = Developer("Shreejeeb","Infosys",23,"Python");
    d.BugFix();

    Teacher t= Teacher("Dhiman Mondal","JGEC",48,"Computer Networks");
    t.Lesson();
    return 0;
}