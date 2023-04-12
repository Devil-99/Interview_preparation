// Find all the prime numbers <= n

#include <iostream>
#include <vector>
using namespace std;
void solve(int n, vector<bool>& primes)
{
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;i*j<=n;j++)
            primes[i*j]=false;
    }
}

int main() {
    int n=5;
    // cin>>n;
    vector<bool> primes(n+1,true);
    solve(n,primes);

    for(int i=2;i<=n;i++)
        if(primes[i])
            cout<<i<<" ";
    cout<<endl;

    return 0;
}

