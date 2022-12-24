// You are given an integer array nums. You are initially positioned at the array's first index,
// and each element in the array represents your maximum jump length at that position.

// For Jump Game 1, Return true if you can reach the last index, or false otherwise.
// For Jump Game 2, Return minimum number of jump required to reach end. You can definitely reach to the end.

// For Jump Game 3, Given an array of non-negative integers arr, you are initially positioned at start index of the array.
// When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

#include <bits/stdc++.h>
using namespace std;

bool jumpGame1(vector<int> &a)
{
    int n=a.size();
    int s=n-1;

    for(int i=n-2;i>=0;i--){
        if(i+a[i]>=s)
            s=i;
    }
    if(s!=0)
    return false;
    return true;
}

int jumpGame2(vector<int> &a){
    int n=a.size();
    vector<int>jumps(n,INT_MAX);
    jumps[0]=0;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(j+a[j]>=i)
                jumps[i]=min(jumps[i],jumps[j]+1);
        }
    }
    return jumps[n-1];
}

bool memoization(vector<int>& arr, int idx, vector<int>&dp){
    if(idx<0 || idx>=arr.size())
        return false;
    if(arr[idx]==0)
        return dp[idx]=true;
    if(dp[idx]!=-1)
        return dp[idx];
    dp[idx]=false;
    return dp[idx] = memoization(arr,idx+arr[idx],dp) || memoization(arr,idx-arr[idx],dp);
}
bool jumpGame3(vector<int>& arr, int start) {
    vector<int>dp(arr.size(),-1);
    return memoization(arr,start,dp);
}

int main() {
    vector<int>array={2,3,1,1,4};
    cout<<jumpGame1(array)<<endl;
    cout<<jumpGame2(array)<<endl;

    vector<int>arr={4,2,3,0,3,1,2};
    int start=5;
    cout<<jumpGame3(arr,start);

    return 0;
}