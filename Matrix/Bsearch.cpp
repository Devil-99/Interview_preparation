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
bool solve()
{
    int r,c;
    cin>>r>>c;
    int matrix[r][c];
    fr(i,0,r)
    {
        fr(j,0,c)
        cin>>matrix[i][j];
    }
    int target;
    cin>>target;

    int l=0,u=r-1,mid,x,y;
        while(l<=u)
        {
            mid=(u+l)/2;
            x=matrix[mid][0],y=matrix[mid][c-1];
            //cout<<x<<" "<<y;
            if(x==target || y==target)
                return true;
            else if(x<=target && y>=target)
            {
                return binary_search(&matrix[mid][0],&matrix[mid][c-1],target);
            }
            else if(target<x)
            {
                u=mid-1;
            }
            else if(target>y)
            {
                l=mid+1;
            }
        }
        return false;
}
int main() {
cout<<solve();
    return 0;
}