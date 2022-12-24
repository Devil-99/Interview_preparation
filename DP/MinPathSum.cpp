// In a grid of row*col, suppose you are in (0,0) position and you have to go to the last element.
// Output the total possible unique way to go to the last element from first.

#include <bits/stdc++.h>
using namespace std;
int memoization(int row, int col, int i, int j,vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if(i<0||j<0)
        return INT_MAX;
    if(i==0 && j==0)
        return grid[0][0];
    
    if(dp[i][j]!=-1)
        return dp[i][j];

    int up,left=INT_MAX;

    if(i>0) up = grid[i][j]+memoization(row,col,i-1,j,grid,dp);
    if(j>0) left = grid[i][j]+memoization(row,col,i,j-1,grid,dp);
    return dp[i][j] = min(up,left);
}

int main() {
    int row=2,col=3;
    vector<vector<int>> grid = { {5,9,6},{11,5,2} };
    vector<vector<int>> dp(row,vector<int>(col,-1));
    int ans1 = memoization(row,col,row-1,col-1,grid,dp);
   
    cout<<ans1;
    return 0;
}