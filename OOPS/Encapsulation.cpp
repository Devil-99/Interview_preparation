#include <bits/stdc++.h>
using namespace std;

class employee {
private:
    string name,company;
    int age;
public:
// manually made constructor
    employee(string Name,string Company,int Age)
    {
        name=Name;
        company=Company;
        age=Age;
    }

// these are the setters and getters for accessing the private variable
    void setName(string Name){name=Name;}
    string getName(){return name;}

    void setCompany(string Company){company=Company;}
    string getCompany(){return company;}

    void setAge(int Age){
        if(Age>=18)
        age=Age;
    }
    int getAge(){return age;}

    void print()
    {
        cout<<"Name is- "<<name<<endl;
        cout<<"Company is- "<<company<<endl;
        cout<<"Age is- "<<age<<endl;
    }
};

int main() {

    employee emp1=employee("Souvik","GS",22);
    emp1.print();

    employee emp2=employee("Nilesh","GFG",35);
    emp2.print();

    // accessing the variables and changing its properties
    emp1.setAge(25);
    cout<<emp1.getName()<<" is "<<emp1.getAge()<<" years old"<<endl;

    return 0;
}