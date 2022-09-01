// Given a frog on the 1st step of an N stairs of a staircase and he has to go to the Nth step.
// He can only jump by 1 stair or 2 stairs at a time.
// Energy lost by the frog is the absolute difference between the 2 stairs.
// Find minimum value of energy lost to reach Nth stair.

#include <bits/stdc++.h>
using namespace std;

// Memoization (Recursive DP)
int frogJump(int idx,vector<int>&dp,vector<int> stairs,int n)
{
    if(idx==0) return 0;

    int oneStep=INT_MAX,twoStep = INT_MAX;
    if(dp[idx-1]==-1)
        oneStep = abs(stairs[idx]-stairs[idx-1]) + frogJump(idx-1,dp,stairs,n);
    else
        oneStep = abs(stairs[idx]-stairs[idx-1]) + dp[idx-1];

    if(idx>1){
        if(dp[idx-2]==-1)
        twoStep = abs(stairs[idx]-stairs[idx-2]) + frogJump(idx-2,dp,stairs,n);
        else
        twoStep = abs(stairs[idx]-stairs[idx-2]) + dp[idx-2];
    }

    dp[idx] = min(oneStep,twoStep);
    return dp[idx];
}

// Tabulation (Iterative version)
int frogJump2(vector<int>stairs,int n) {
    vector<int>dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++) {
        int oneStep,twoStep=INT_MAX;
        oneStep = abs(stairs[i]-stairs[i-1]) + dp[i-1];
        if(i>1)
            twoStep = abs(stairs[i]-stairs[i-2]) + dp[i-2];

        dp[i]=min(oneStep,twoStep);
    }
    return dp[n-1];
}

int main() {
    int n=8;
    vector<int> stairs={7,4,4,2,6,6,3,4};
    vector<int> dp(n,-1);
    cout<<frogJump(n-1,dp,stairs,n);
    cout<<frogJump2(stairs,n);
return 0;
}