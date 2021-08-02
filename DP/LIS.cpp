// Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int c=1,mx=0;
    for(int i=0;i<n;i++)
    {
        int temp=a[i];
        mx=max(c,mx);
        c=1;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>temp)
            {
                c++;
                temp=a[j];
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}