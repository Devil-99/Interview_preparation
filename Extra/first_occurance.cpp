#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	map<char,int>m,p;
	for(int i=0;i<s.length();i++)
    {m[s[i]]++;
	p[s[i]]=i;}
	multimap<int,char>mp;
	
	for(auto it:m)
	{
	    mp.insert({it.second,it.first});
	    //cout<<it.first<<"->"<<it.second<<endl;
	}
	char ans;
	int mn=INT_MAX;
	for(auto i:mp)
	{
	    if(i.first==1)
	    {
	        int idx=p[i.second];
	        if(idx<mn)
	        {
	            ans=i.second;
	            mn=idx;
	        }
	    }
	}
	cout<<ans;
	return 0;
}