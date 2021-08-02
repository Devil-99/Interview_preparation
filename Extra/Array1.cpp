/*                	SOUVIK MAJI 
               JALPAIGURI GOVT. ENGG. COLLEGE
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pb push_back
#define ff first
#define ss second
#define Mp make_pair
#define endl "\n"
#define SIZE 1000000
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
{
unsigned int count=0;
while(n)
{
  n&=(n-1);
  count++;
}
return count;
}

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
ll MIN(ll x,ll y,ll z){ return min(min(x, y),z); }
ll MAX(ll x,ll y,ll z){ return max(max(x, y),z); }

bool f(ll x,ll y) {return x>y;}

void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    fr(i,0,n)
    cin>>a[i];
    
    ll x=INT_MAX,ans=0;
    fr(i,0,n)
    {
        x=min(a[i],x);
        ans=max(a[i]-x,ans);
    }
    if(ans==0)
    cout<<"UNFIT"<<endl;
    else
    cout<<ans<<endl;
}

int main() {
	fio;
	int t=1;
	cin>>t;
	while(t--)
	{
	// clock_t start,end;
	// double time;
	// begin=clock();

	    solve();

	// end=clock();
	// time=(double)(end-start)/CLOCKS_PER_SEC;
	// cout<<time<<endl;
	}
	return 0;
}