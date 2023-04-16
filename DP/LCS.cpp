#include <bits/stdc++.h>
using namespace std;

int recursiveDP(string s, string t, int idx1, int idx2, vector<vector<int>>& dp)
{
    if(idx1<0 || idx2<0)
        return 0;

    if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];

    if(s[idx1]==t[idx2])
        return dp[idx1][idx2] = 1+recursiveDP(s,t,idx1-1,idx2-1,dp);
    else
        return dp[idx1][idx2] = max(recursiveDP(s,t,idx1-1,idx2,dp) , recursiveDP(s,t,idx1,idx2-1,dp));

}

int tabulation(string s, string t){
    int n=s.length(),m=t.length();
    vector<vector<int>> dp(s.length()+1 , vector<int>(t.length()+1,-1));

    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
                dp[i][j]= 1+dp[i-1][j-1];
            else
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    string s="acd",t="aed";

    int idx1 = s.length()-1, idx2 = t.length()-1;
    vector<vector<int>> dp(s.length() , vector<int>(t.length(),-1));
    cout<<recursiveDP(s,t,idx1,idx2,dp)<<endl;

    cout<<tabulation(s,t)<<endl;

    return 0;
}