/*                	SOUVIK MAJI 
        Github: https://github.com/Devil-99
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define dd double
#define pb push_back
#define ff first
#define ss second
#define Mp make_pair
#define endl "\n"
#define SIZE 1000000
#define mod 1000000007
#define inf 1e18
#define pi pair<int,int> 
#define vi vector<int>
#define vvi vector<vector<int>>
#define fr(i,x,n) for(int i=x;i<=n-1;i++) 
#define rf(i,x,n) for(int i=n-1;i>=x;i--)
#define toUpper(s) transform(s.begin(),s.end(),s.begin(),::toupper)
#define toLower(s) transform(s.begin(),s.end(),s.begin(),::tolower)
#define fio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

template <typename T>
//" cout << variable_name " signifies what the below line means.
ostream& operator<< (ostream& os, vector<T> &vec){
    os << "[";
    for(int i=0;i<vec.size();++i){
        os << vec[i];
        if( i!= vec.size()-1)
            os << ",";
    }
    os << "]";
    return os;
}

unsigned int countSetbit(int n){
    unsigned int count=0;
    while(n){
      n&=(n-1);
      count++;
    }
    return count;
}

ll factorial(ll n){
    ll ans=1, i;
    for(i=2;i<=n;i++)
        ans*=i;
    return ans;
}

ll power(ll n,ll p){
    if (p==0) 
        return 1; 
    else if (p%2==0) 
        return power(n,p/2)*power(n,p/2); 
    else
        return n*power(n,p/2)*power(n,p/2);
}

template <typename T>
T min(T a, T b, T c){
    return min(a, min(b, c));
}
template <typename T>
T max(T a, T b, T c){
    return max(a, max(b, c));
}

void solve(){
    
}

int main() {
	fio;
	int t=1;
	cin>>t;
	while(t--)
	    solve();
	    
	return 0;
}