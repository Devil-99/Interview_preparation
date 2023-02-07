#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int i=0,j=0,ans=INT_MAX,sum=0,n=nums.size();
    while(j<n){
        sum+=nums[j];
        while(sum>=target){
            if(ans>j-i+1){
                ans=j-i+1;
            }
            sum-=nums[i];
            i++;
        }
        j++;
    }
    return ans==INT_MAX?0:ans;
}

int main(){
    int target=7;
    vector<int>nums = {2,3,1,2,4,3};
    cout<<minSubArrayLen(target,nums)<<endl;
return 0;
}