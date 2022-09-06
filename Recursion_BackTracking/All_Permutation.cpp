#include <bits/stdc++.h>
using namespace std;

void permutation(vector<int>&nums,int index,vector<vector<int>>&ans){
    if(index==nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        permutation(nums,index+1,ans);
        swap(nums[index],nums[i]);
    }
    return;
}

int main() {
    vector<int>nums={1,2,3};
    vector<vector<int>>ans;
    permutation(nums,0,ans);
    for(auto it:ans)
        {for(auto i:it)
            cout<<i<<" ";
        cout<<endl;}
    return 0;
}