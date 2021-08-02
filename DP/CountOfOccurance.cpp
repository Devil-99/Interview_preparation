// No of count of a string into another string

#include <bits/stdc++.h>
using namespace std;
int solve(string s,string t)
{
    int n=s.length(),m=t.length();
    int dp[m+1][n+1];
    // if s is empty then no matching
    for(int i=0;i<=m;i++)
    dp[i][0]=0;
    // if t is empty then for every substring of s there is an empty string.. so count is 1 always
    for(int i=0;i<=n;i++)
    dp[0][i]=1;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(t[i-1]==s[j-1])
            dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            else
            dp[i][j]=dp[i][j-1];
        }
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];
}
int main() {
    string s,t;
    cin>>s>>t;

    cout<<solve(s,t);
    return 0;
}