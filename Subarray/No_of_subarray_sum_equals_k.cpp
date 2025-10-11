// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int>prefix;
    int sum=0;
    for(auto it:nums){
        sum+=it;
        prefix.push_back(sum);
    }
    int count=0;
    map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        if(prefix[i]==k)
            count++;
        if(mp.find(prefix[i]-k)!=mp.end())
            count+=mp[prefix[i]-k];
        mp[prefix[i]]++;
    }
    return count;
}

int main() {
    vector<int>nums={1,2,3};
    int k=3;
    cout<<subarraySum(nums,k);
    return 0;
}