#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>&a)
{
    for(int i=1;i<a.size();i++){
        int j=i;
        while(j>0 && a[j]<a[j-1]){
            cout<<"swapping of "<<a[j-1]<<","<<a[j]<<endl;
            swap(a[j],a[j-1]);
            j--;
        }
    }
}

int main() {
    vector<int> a={7,6,8,5};
    insertion_sort(a);
    for(auto it:a)
    cout<<it<<" ";
    return 0;
}