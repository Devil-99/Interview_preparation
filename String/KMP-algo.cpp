#include<bits/stdc++.h>
using namespace std;

void LPS(string txt,int m,int* lps)
{
    int len=0;
    lps[0]=0;
    for(int i=1;i<m;i++)
    {
        if(txt[i]==txt[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            len=lps[len-1];
            else
            {lps[i]=0;
            i++;}
        }
    }
}
void KMPsearch(string s,string txt)
{
    int n=s.length();
    int m=txt.length();
    int lps[m];
    LPS(txt,m,lps);

    int i=0,j=0;
    while(i<n)
    {
        if(s[i]==txt[j])
        {
        i++;
        j++;
        }
        if(j==m)
        {
            cout<<"String matched at index "<<i-j;
            j=lps[j-1];
        }
        else if(i<n && s[i]!=txt[j])
            if(j!=0)
            j=lps[j-1];
            else
            i++;
    }

}
int main()
{
    string s,txt;
    cin>>s>>txt;
    KMPsearch(s,txt);
return 0;
}