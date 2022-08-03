#include <bits/stdc++.h>
using namespace std;

// Brute force O(2^n)
int count(int a[],int sum,int n,int i)
{
    if (sum==0) return 1;
    if(i>=n || sum<0) return 0;

    int taken=count(a,sum-a[i],n,i);
    int notTaken=count(a,sum,n,i+1);
    return taken+notTaken;
}

// DP approach O(n*sum)
int countDp(int a[],int sum,int n,int i,vector<vector<int>> &dp)
{
    if (sum==0) return 1;
    if(i>=n || sum<0) return 0;

    if(dp[i][sum]!=-1)
        return dp[i][sum];

    int taken=count(a,sum-a[i],n,i);
    int notTaken=count(a,sum,n,i+1);
    dp[i][sum]=taken+notTaken;

    return dp[i][sum];
}


int main() {

    int s[]={1,2,3};
    int sum=4,n=3;

    //cout<<count(s,sum,n,0);

    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    cout<<countDp(s,sum,n,0,dp);
    
    return 0;
}