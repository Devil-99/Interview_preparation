#include<bits/stdc++.h>
using namespace std;

void LPS(string txt,int* lps)
{
    int idx=0;
    lps[0]=0;
    for(int i=1;i<txt.size();)
    {
        if(txt[i]==txt[idx]){
            idx++;
            lps[i]=idx;
            i++;
        }
        else{
            if(idx!=0)
                idx=lps[idx-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void KMPsearch(string s,string target,int* lps)
{
    int n=s.length();
    int m=target.length();

    int i=0,j=0;
    while(i<n)
    {
        if(s[i]==target[j])
        {
        i++;
        j++;
        }
        if(j==m)
        {
            cout<<"String matched at index "<<i-j;
            j=lps[j-1];
        }
        else if(i<n && s[i]!=target[j])
            if(j!=0)
            j=lps[j-1];
            else
            i++;
    }

}
int main()
{
    string s,target;
    cin>>s>>target;

    int m=target.size();
    int lps[m];
    LPS(target,lps);

    KMPsearch(s,target,lps);
return 0;
}