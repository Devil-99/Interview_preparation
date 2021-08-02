/*                	SOUVIK MAJI 
   JALPAIGURI GOVT. ENGG. COLLEGE*/
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
    int r,c;
    cin>>r>>c;
    int matrix[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cin>>matrix[i][j];
    }

    int k=0,l=0,i;
    while(k<r && l<c)
    {
        for(i=l;i<c;++i)
        cout<<matrix[k][i]<<" ";
        k++;
        
        for(i=k;i<r;++i)
        cout<<matrix[i][c-1]<<" ";
        c--;
        
        if(k<r)
        {for(i=c-1;i>=l;--i)
        cout<<matrix[r-1][i]<<" ";
        r--;}
        
        if(l<c)
        {for(i=r-1;i>=k;--i)
        cout<<matrix[i][l]<<" ";
        l++;}
    }
}
int main() {
solve();
    return 0;
}