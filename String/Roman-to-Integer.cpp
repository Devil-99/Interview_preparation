#include<bits/stdc++.h>
using namespace std;

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int main()
{
    string str;
    cin>>str;
    int sum=value(str[0]),l=str.length();
    for(int i=1;i<l;i++)
    {
        int cur=value(str[i]),prev=value(str[i-1]);
        if(prev<cur)
        {
            sum-=prev;
            sum+=(cur-prev);
        }
        else
        sum+=cur;
    }
    cout<<sum<<endl;
return 0;
}