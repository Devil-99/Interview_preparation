#include <bits/stdc++.h>
using namespace std;

int x;

void solve(int *x){
    *x=7;
cout<<"solve "<<*x<<endl;
}

int main(){
x=5;
cout<<"main "<<x<<endl;
solve(&x);
cout<<"main "<<x<<endl;
return 0;
}