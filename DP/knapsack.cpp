#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,Wt;
    cin>>n>>Wt;
    int p[n+1],w[n+1];
    p[0]=0,w[0]=0;
    for(int i=1;i<=n;i++)
    cin>>p[i];
    for(int i=1;i<=n;i++)
    cin>>w[i];

    int dp[n+1][Wt+1];
    for(int i=0;i<=Wt;i++)
    dp[0][i]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=Wt;j++)
        {
            //cout<<j-w[i]<<" "<<dp[i-1][j-w[i]]<<endl;
            if(j-w[i]<0)
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=max(dp[i-1][j], (dp[i-1][j-w[i]]+p[i]) );
        }
    }
    
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=Wt;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][Wt]<<endl;
    return 0;
}