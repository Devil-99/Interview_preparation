#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int n=s.length();
    bool a[n][n];
    
    memset(a,0,sizeof(a));
    
    int max=1;
    for(int i=0;i<n;++i)
    a[i][i]=true;
    
    int start=0,x=n-1;
    for(int i=0;i<n;++i)
    {
        if(s[i]==s[i+1])
        {a[i][i+1]=true;
        start=i;
        max=2;
        x=min(start,x);
        }
    }
    
    for(int k=3;k<=n;++k)
    {
        for(int i=0;i<n-k+1;++i)
        {
            int j=i+k-1;
            if(s[i]==s[j] && a[i+1][j-1])
            {a[i][j]=true;
            if(k>max)
            {
                start=i;
                max=k;
            }
            }
        }
    }
    if(max==2)
    for(int i=x;i<=x+max-1;i++)
    cout<<s[i];
    else
    for(int i=start;i<=start+max-1;i++)
    cout<<s[i];
    cout<<endl; 
	return 0;
}