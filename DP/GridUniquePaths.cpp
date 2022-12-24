// In a grid of row*col, suppose you are in (0,0) position and you have to go to the last element.
// Output the total possible unique way to go to the last element from first.

#include <bits/stdc++.h>
using namespace std;
int memoization(int row, int col, int i, int j,vector<vector<int>> &dp)
{
    if(i>=row||j>=col)
        return 0;
    if(i==row-1&&j==col-1)
        return 1;
    
    if(dp[i][j]!=-1)
        return dp[i][j];

    return dp[i][j] = memoization(row,col,i+1,j,dp)+memoization(row,col,i,j+1,dp);
}
int tabulation(int row, int col){
    int dp[row][col];
    dp[0][0]=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int rowwise=0,colwise=0;
            if(i>0) rowwise = dp[i-1][j];
            if(j>0) colwise = dp[i][j-1];
            dp[i][j] = rowwise+colwise;
        }
    }
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[row-1][col-1];
}
int main() {
    int row=3,col=7;
    vector<vector<int>> dp(row,vector<int>(col,-1));
    // int ans1 = memoization(row,col,0,0,dp);
    int ans2 = tabulation(row,col);
    cout<<ans2;
    return 0;
}