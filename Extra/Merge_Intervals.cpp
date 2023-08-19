// Merge all the overlapping intervals and print the distinct intervals

#include<bits/stdc++.h>
using namespace std;

int merge(vector<vector<int>> intervals) {
vector<vector<int>> ans;
int n=intervals.size();
sort(intervals.begin(),intervals.end());
for(int i=0;i<intervals.size();i++) {
    if(!ans.empty() && ans.back()[1]>=intervals[i][0]) {
        ans.back()[1]=max(intervals[i][1],ans.back()[1]);
    }
    else
        ans.push_back(intervals[i]);
}
return ans.size();
}

int main() {
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    int ans = merge(intervals);
    cout<<ans<<endl;
    return 0;
}