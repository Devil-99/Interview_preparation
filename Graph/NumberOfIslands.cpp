#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>&grid,int i,int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1')
        return;
    
    grid[i][j]='2';
    
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
}
int numIslands(vector<vector<char>>& grid) {
    int count=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){
                dfs(grid,i,j);
                count++;
            }
        }
    }
    return count;
}

// This is just the code snippet, which can't be run.
// Actual code - https://leetcode.com/problems/number-of-islands/submissions/ - My Submission