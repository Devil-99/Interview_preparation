// Given an array, you have to generate all the subarrays of the array.
// The brute force approach for any subarray problem.

#include <iostream>
#include <vector>
using namespace std;

void generateSubarrays(vector<int> arr) {
    vector <int> subarray_sum;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            subarray_sum.push_back(sum);
        }
    }

    for(auto i=subarray_sum.begin();i<subarray_sum.end();i++)
        cout<<*i<<" ";
    cout<<endl;
}

int main () {
vector <int> arr = {2, 3, 5, -2, 7, -4};
generateSubarrays(arr);
return 0;
}