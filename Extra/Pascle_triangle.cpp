#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        for(int i=0;i<numRows;i++)
        {
            ans[i].resize(i+1);
            ans[i][0]=ans[i][i]=1;
            
            for(int j=1;j<i;j++)
            ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
        return ans;
    }
int main() {
    int n;
    cin>>n;
    vector<vector<int>>ans;
    ans=generate(n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}