// Maximum (Contiguous)Subarray Sum

#include <bits/stdc++.h>
using namespace std;
int kadane(vector<int> nums)
{
    int sum=0,mx=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i]; //current sum
        mx=max(sum,mx);  //max so far
        sum=max(sum,0);
    }
    return mx;
}
int main() {
    int n,x;
    cout<<"Enter the no of elements";
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {cin>>x;
    nums.push_back(x);}
    int ans=kadane(nums);
    cout<<ans<<endl;
    return 0;
}