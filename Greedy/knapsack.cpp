#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,W;
    cout<<"Enter the number of object and maximum weight of the knapsack"<<endl;
    cin>>n>>W;
    int p[n],w[n];
    for(int i=0;i<n;i++)
    cin>>p[i];
    for(int i=0;i<n;i++)
    cin>>w[i];

    vector<pair<double,int>> ratio;
    double x;
    for(int i=0;i<n;i++)
    {x= double(p[i])/double(w[i]);
    ratio.push_back(make_pair(x,i));}
    sort(ratio.begin(),ratio.end());

    double profit=0;
    int idx;
    for(int i=n-1;i>=0;i--)
    {
        idx=ratio[i].second;
        if(W>w[idx])
        {profit+=p[idx];
        W-=w[idx];}
        else
        break;
    }
    profit+=(double(W)/double(w[idx]))*double(p[idx]);

    cout<<profit<<endl;

return 0;
}
/*
7 15
10 5 15 7 6 18 3
2 3 5 7 1 4 1
*/