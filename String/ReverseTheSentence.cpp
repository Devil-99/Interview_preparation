// Reverse the sentence
// input= " the sky is  blue   ";
// output= "blue is sky the"

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseWords(string s) {
    int i=0,l=s.length();
    stack<string> ans;
    string str="";
    while(i<l)
    {
        if(s[i]==' ')
        {
            i++;
            ans.push(str);
            str="";
        }
        else
        {
            str+=s[i];
            i++;
        }
    }
    if(str!="")
    ans.push(str);
    
    string x="";
    while(!ans.empty())
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