#include<bits/stdc++.h>
using namespace std;
string subString (string S)
{
    string ans="";
    int ln=S.length();
    int l=0,len=0,x,y,mx=0;
    map<char,int> v;
    for(int i=0;i<ln;i++)
    {
        l=max(l,v[S[i]]);
        len=max(len,i-l+1);
        v[S[i]]=i+1;
        if(len>mx)
        {
            mx=len;
            x=l;
            y=i;
        }
    }
    for(int i=x;i<=y;i++)
    ans+=S[i];
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<subString(s)<<endl;
return 0;
}