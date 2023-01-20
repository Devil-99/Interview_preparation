#include <bits/stdc++.h>
using namespace std;

int recursion(int n)
{
    if(n==0||n==1)
    return n;
    return recursion(n-1)+recursion(n-2);

    // time complexity : exponential
}
int dpApproach(int n)
{
    int dp[n+2];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
int PrevElemStore(int n)
{
    int prev=0,prev2=1,cur;
    for(int i=2;i<=n;i++)
    {
        cur=prev+prev2;
        prev2=prev;
        prev=cur;
    }
    return cur;
}
int main() {
    cout<<dpApproach(6);
    return 0;
}