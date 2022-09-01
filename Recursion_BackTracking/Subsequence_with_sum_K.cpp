// Print all the subsequence whose sum is equal to k

#include<bits/stdc++.h>
using namespace std;

void allSubsequence(int index,int k,int sum,vector<int>temp,vector<int>array) {
    if(index==array.size()) {
        if(sum==k) {
            for(auto it:temp)
                cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    temp.push_back(array[index]);
    sum+=array[index];
    allSubsequence(index+1,k,sum,temp,array);

    temp.pop_back();
    sum-=array[index];
    allSubsequence(index+1,k,sum,temp,array);
}

bool oneSubsequence(int index,int k,int sum,vector<int>temp,vector<int>array) {
    if(index==array.size()) {
        if(sum==k) {
            for(auto it:temp)
                cout<<it<<" ";
            cout<<endl;
            return true;
        }
            return false;
    }

    temp.push_back(array[index]);
    sum+=array[index];
    if(oneSubsequence(index+1,k,sum,temp,array))
        return true;
    
    temp.pop_back();
    sum-=array[index];
    if(oneSubsequence(index+1,k,sum,temp,array))
        return true;
    return false;
}

int countSubsequence(int index,int k,int sum,vector<int>array) {
    if(index==array.size()) {
        if(sum==k)
            return 1;
        else
            return 0;
    }

    sum += array[index];
    int l = countSubsequence(index+1,k,sum,array);
    
    sum -= array[index];
    int r = countSubsequence(index+1,k,sum,array);

    return l+r;
}

int main() {
    int n,k;
    cout<<"Enter the size of array:- ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++)
        cin>>array[i];
    cout<<"Enter the required sum:- ";
    cin>>k;
    vector<int>tempArray;
    allSubsequence(0,k,0,tempArray,array);

    oneSubsequence(0,k,0,tempArray,array);

    cout<< countSubsequence(0,k,0,array);

}