#include <bits/stdc++.h>
using namespace std;

int recursiveDp(int idx,vector<int>arr,vector<int>&dp){
    if(idx==0) return arr[idx];
    if(idx<0) return 0;

    int pick,nonpick;

    if(dp[idx]!=-1) return dp[idx];
    
    pick = arr[idx]+recursiveDp(idx-2,arr,dp);
    nonpick = recursiveDp(idx-1,arr,dp);
    
    return dp[idx]=max(pick,nonpick);
}

int main() {
    int n=4;
    vector<int>array={2,1,4,9};
    vector<int>dp(n,-1);
    cout<<recursiveDp(3,array,dp);
    return 0;
}