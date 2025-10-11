#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int start=0, end=start, sum=0, max_length=0;
    vector<int> result;
    while(start<=end && end<nums.size()){
        sum += nums[end];
        while(start<=end && sum>k){
            sum -= nums[start];
            start++;
        }
        if(sum==k){
            max_length = max(max_length, end-start+1);
            result = vector<int>(nums.begin()+start, nums.begin()+end+1);
        }
        end++;
    }
    cout<< max_length <<endl;
    for(int i=0; i<result.size(); i++){
        cout<< result[i] <<" ";
    }
    cout<<endl;
    return 0;
}