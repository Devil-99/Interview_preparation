// Encapsulation is a process of binding the datas and methods together in a class and hide the information from outside
// and giving users only necessary control by some Getter and Setter function to use the class.

#include <bits/stdc++.h>
using namespace std;

class employee {
private:
    string name,company;
    int age;
public:
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

};

int main() {

    employee emp1;
    emp1.setName("Souvik");
    emp1.setCompany("Amazon");
    emp1.setAge(23);

    // accessing the variables and changing its properties
    cout<<emp1.getName()<<" is "<<emp1.getAge()<<" years old"<<endl;

    return 0;
}