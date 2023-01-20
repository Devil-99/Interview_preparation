#include <bits/stdc++.h>
using namespace std;

class example{
    public:
    string name;
    void setName(string s){
        this->name=s;
    }
    void print(){
        cout<<name<<endl;
    }
    example(){
        cout<<"Default constructor"<<endl;
    }
    example(example& temp){
        this->name=temp.name;
    }
};

int main() {
    example myObject1;
    myObject1.setName("Souvik");
    myObject1.print();

    example myObject2(myObject1);
    myObject2.print();

    myObject1.name[0]='M';
    myObject1.print();
    myObject2.print();

    return 0;
}