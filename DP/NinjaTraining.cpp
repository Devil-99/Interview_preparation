#include <bits/stdc++.h>
using namespace std;

// Recursive code with memoization
int training(int days, int prevTask, vector<vector<int>>points, vector<vector<int>>&dp){
    int mx=0;
    if(days==0){
        for(int curTask=0;curTask<3;curTask++){
            if(curTask != prevTask)
                mx = max(mx,points[days][curTask]);
        }
        return mx;
    }

    if(dp[days][prevTask]!=-1) return dp[days][prevTask];

    for(int curTask=0;curTask<3;curTask++){
        if(curTask != prevTask){
            int point = points[days][curTask] + training(days-1,curTask,points,dp);
            mx = max(mx,point);
        }
    }
    return dp[days][prevTask]=mx;
}

// Tabulation (Iterative version)
int Training(int n, vector<vector<int>>points){

    vector<vector<int>>dp(n,vector<int>(4,0));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));

    for(int days=1;days<n;days++){
        for(int prevTask=0;prevTask<=3;prevTask++){
            int mx=0;
            for(int curTask=0;curTask<3;curTask++){
                if(curTask != prevTask){
                    int point = points[days][curTask] + dp[days-1][curTask];
                    mx = max(mx,point);
                }
            }
            dp[days][prevTask]=mx;          // You can omit the mx and point variable by directly assign the value in dp[days][task].
        }
    }
    return dp[n-1][3];
}

int main() {
    int n=3;
    vector<vector<int>> points={{18,11,19},{4,13,7},{1,8,13}};
    vector<vector<int>>dp(n,vector<int>(4,-1));
    cout<<training(n-1,3,points,dp)<<endl;

    cout<<Training(n,points)<<endl;
    return 0;
}