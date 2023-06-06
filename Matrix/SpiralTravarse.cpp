#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int i=0,j=0,n=matrix.size(),m=matrix[0].size();
    int  u = 0, d = n - 1, l = 0, r = m - 1, p = 0;
    vector<int> order(m * n);
    while (u <= d && l <= r) {
        for (int col = l; col <= r; col++)
            order[p++] = matrix[u][col];
        if (++u > d)    break;

        for (int row = u; row <= d; row++)
            order[p++] = matrix[row][r];
        if (--r < l)    break;

        for (int col = r; col >= l; col--)
            order[p++] = matrix[d][col];
        if (--d < u)    break;

        for (int row = d; row >= u; row--)
            order[p++] = matrix[row][l];
        if (l++ > r)    break;
    }
    return order;
}

vector<vector<int>> generateMatrix(int n) {
    int i=0,j=0,m=n;
    int  u = 0, d = n - 1, l = 0, r = m - 1, p = 1;
    vector<vector<int>> order(n,vector<int>(m));
    while (u <= d && l <= r) {
        for (int col = l; col <= r; col++)
            order[u][col]=p++;
        if (++u > d)    break;

        for (int row = u; row <= d; row++)
            order[row][r]=p++;
        if (--r < l)    break;

        for (int col = r; col >= l; col--)
            order[d][col]=p++;
        if (--d < u)    break;

        for (int row = d; row >= u; row--)
            order[row][l]=p++;
        if (l++ > r)    break;
    }
    return order;
}

int main() {
    int n=3,m=3;
    vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
    
    vector<int> spiralTravarse=spiralOrder(matrix);

    for(auto i:spiralTravarse)
    cout<<i<<" ";
    cout<<endl;

    int l=3;
    vector<vector<int>> grid=generateMatrix(l);

    for(auto i:grid){
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}