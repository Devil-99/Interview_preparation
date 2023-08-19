// Problem statement :- 
// There is an array of skill level ratings of students and you are provided with a minimum value(k).
// You have to pair up the students whose ratings differ by minimum k.
// you have to find maximum no of such pairs

// Basically :- You have to find the min value that is >= key in binary search 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n;
    int a[n]; 
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>k;
    
    sort(a,a+n);
    
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int x=a[i]+k;
        int idx=lower_bound(a,a+n,x)-a;
        if(idx<n)
        v.push_back(make_pair(a[i],a[idx]));
    }
    
    for(auto it:v)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
	return 0;
}