#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int sum=0,mod=0,ans=0;
    map<int,int>mp;
    mp[0]++;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        mod=sum%k;
        if(mod<0)
            mod+=k;
        if(mp.find(mod)!=mp.end()){
            ans+=mp[mod];
        }
        mp[mod]++;
    }
    return ans;
}

int main(){
    vector<int>nums={4,5,0,-2,-3,1};
    int k=5;
    cout<<subarraysDivByK(nums,k);
    return 0;
}