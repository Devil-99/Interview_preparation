// Sum of first n numbers

#include<bits/stdc++.h>
using namespace std;

// Parameterised way
void func1(int n,int sum) {
    if(n<1) {
        cout<<sum;
        return;
    }
    func1(n-1,sum+n);
}

// Functional way
int func2(int n) {
    if(n==0)
        return 0;
    return n+func2(n-1);
}

int main() {
    int n;
    cout<<"Enter the number :- ";
    cin>>n;
    // func1(n,0);
    cout<<func2(n);
}