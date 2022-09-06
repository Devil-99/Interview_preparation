#include <bits/stdc++.h>
using namespace std;

void func(int n,int k,int index,vector<int> &v,vector<vector<int>> &ans){
    if(k==0){
        ans.push_back(v);
        return;
    }
    for(int i=index;i<=n;i++){
        v.push_back(i);
        func(n,k-1,i+1,v,ans);
        v.pop_back();
    }  
}

int main() {
    int n=4,k=3;
     vector<vector<int>> ans;
    vector<int>v;
    func(n,k,1,v,ans);
    for(auto it:ans)
        {for(auto i:it)
            cout<<i<<" ";
        cout<<endl;}
    return 0;
}