#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int b[],int array[],int n,int m)
{
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
            array[k++]=a[i++];
        else
            array[k++]=b[j++];
    }
    while(i<n)
    array[k++]=a[i++];
    while(j<m)
    array[k++]=b[j++];
}
int main() {
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    
    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<m;i++)
    cin>>b[i];

    int ans[n+m];

    merge(a,b,ans,n,m);

    for(int i=0;i<n+m;i++)
    cout<<ans[i]<<" ";
    return 0;
}