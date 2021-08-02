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
string solve(int num)
{
    string s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int a[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string ans="";
        for(int i=0;num>0;i++)
        {
            while(num>=a[i])
            {
                ans+=s[i];
                num-=a[i];
            }
        }
        return ans;
}
int main() {
    int num;
    cin>>num;
    string ans=solve(num);
    cout<<ans<<endl;
    return 0;
}