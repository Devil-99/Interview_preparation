// Print all possible subsequences of an array.

#include<bits/stdc++.h>
using namespace std;

void func(int index,vector<int>temp,vector<int>array) {
    if(index>=array.size()) {
        for(auto it:temp)
            cout<<it<<" ";
        cout<<endl;
        return;
    }
    temp.push_back(array[index]);
    func(index+1,temp,array);

    temp.pop_back();
    func(index+1,temp,array);
}

int main() {
    int n;
    cout<<"Enter the size of array:- ";
    cin>>n;
    vector<int>array(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
        cin>>array[i];
    cout<<endl;
    vector<int>tempArray;
    func(0,tempArray,array);
}