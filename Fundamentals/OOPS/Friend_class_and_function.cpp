// A friend function can be granted special access to private and protected members of a class in C++.
// It can be a global function, or a Member function of another class.

#include <bits/stdc++.h>
using namespace std;

class base{
    private:
        int private_variable;
    protected:
        int protected_variable;
    public:
        base(){
            private_variable=10;
            protected_variable=20;
        }
        friend void friendFunction(base);
};

void friendFunction(base obj){
    cout<<obj.private_variable+obj.protected_variable<<endl;
}

int main(){
    base obj;
    friendFunction(obj);
    return 0;
}