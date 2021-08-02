// Reverse the sentence
// input= " the sky is  blue   ";
// output= "blue is sky the"

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int i=0,l=s.length();
    stack<string> ans;
    string str="";
    bool f=0;
    while(i<l)
    {
        if(s[i]==' ')
        {
            i++;
            if(f){
            ans.push(str);
            str="";
            f=0;}
        }
        else
        {
            str+=s[i];
            i++;
            f=1;
        }
    }
    if(str!="")
    ans.push(str);
    
    string x="";
    // while(!ans.empty())
    // {
    //     x+=ans.top();
    //     ans.pop();
    // }
    // return x;
    while(1)
    {
        x+=ans.top();
        ans.pop();
        if(ans.empty())
            return x;
        x+=" ";
    }
}
int main()
{
    string s;
    getline(cin,s);
    string ans=reverseWords(s);
    cout<<ans;
    return 0;
}