// Find all the prime numbers <= n

#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    bool a[n+1];
    memset(a,true,sizeof(a));
    a[0]=0;
    a[1]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;i*j<=n;j++)
        {
            a[i*j]=false;
        }
    }
    for(int i=2;i<=n;i++)
    if(a[i])
    cout<<i<<" ";
    cout<<endl;
}

int main() {
    int n;
    cin>>n;
    solve(n);
    return 0;
}