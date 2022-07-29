
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pb push_back
#define ff first
#define ss second
#define Mp make_pair
#define SIZE 1000000
#define mn 1000000
#define fr(i,x,n) for(int i=x;i<=n-1;i++) 
#define rf(i,x,n) for(int i=n-1;i>=x;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
void swap(int *a,int *b)
{
    int k=*a;
    *a=*b;
    *b=k;
}
unsigned int countSetbit(int n)
{unsigned int count=0;
    while(n)
    {
      n&=(n-1);
      count++;
    }
return count;}
ll pwr(ll n,ll p)
{
    if (p==0)
        return 1;
    else if (p%2==0)
        return pwr(n,p/2)*pwr(n,p/2);
    else
        return n*pwr(n,p/2)*pwr(n,p/2);
}
ll hcf(ll a,ll b)
{
    if(b==0)
        return a;
    return hcf(b,a%b);
}
bool f(ll x,ll y) {return x>y;}
void solve()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    fr(i,0,n)
    cin>>a[i];

    map<int,int>m;
    fr(i,0,n)
    {
        int y=a[i]%x;
        if(m.find(y)==m.end())
        m[y]=1;
        else
        m[y]++;
    }
    int c=0;
    for(auto it:m)
    {
        int y=x-it.ff;
        if(m.find(y)!=m.end())
        {
            if(it.ss==0 && m[y]!=0)
            {
                c++;
                m[y]--;
                cout<<it.ff<<"->"<<it.ss<<" "<<y<<"->"<<m[y]<<endl;
            }
            else if(it.ss!=0 && m[y]==0)
            {
                c++;
                it.ss--;
                cout<<it.ff<<"->"<<it.ss<<" "<<y<<"->"<<m[y]<<endl;
            }
            else if(it.ss!=0 && m[y]!=0)
            {
                c++;
                it.ss--;
                m[y]--;
                cout<<it.ff<<"->"<<it.ss<<" "<<y<<"->"<<m[y]<<endl;
            }
        }
    }

    cout<<c<<endl;
    // for(auto it:m)
    // cout<<it.ff<<" "<<it.ss<<endl;
}
int main() {
    fio;
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}