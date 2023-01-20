#include <bits/stdc++.h>
using namespace std;

bool memoization(vector<int>array,int sum,int idx, vector<vector<int>> &dp)
{
    if(sum==0)
        return true;
    
    if(idx==0)
        return (sum==array[idx]);

    if(dp[idx][sum]!=-1)
        return dp[idx][sum];
    bool nonTake = memoization(array,sum,idx-1,dp);
    bool take = false;
    if(sum>=array[idx])
        take = memoization(array,sum-array[idx],idx-1,dp);

    return dp[idx][sum] = take | nonTake;
}

bool tabulation(vector<int>array,int sum){
    int n=array.size();
    vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][array[0]] =true;

    for(int idx=1;idx<n;idx++){
        for(int k=1;k<=sum;k++){
            bool nonTake = dp[idx-1][k];
            bool take=false;
            if(k>=array[idx])
                take = dp[idx-1][sum-array[idx]];
            dp[idx][k]= take|nonTake;
        }
    }

    for(auto it:dp){
        for(auto i:it)
            cout<<i<<' ';
        cout<<endl;
    }
    return dp[n-1][sum];
}

int main() {
    int k=4,n=4;
    vector<int>array={1,3,2,4};
    vector<vector<int>> dp(n ,vector<int>(k+1,-1));
    // cout<<memoization(array,k,array.size()-1,dp)<<endl;
    cout<<tabulation(array,k);
    // for(auto it:dp){
    //     for(auto i:it)
    //         cout<<i<<' ';
    //     cout<<endl;
    // }
    return 0;
}