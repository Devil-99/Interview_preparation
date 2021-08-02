#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no of process: ";
    cin>>n;

    int AT[n],BT[n],CT[n],TAT[n],WT[n],RT[n];
    cout<<"Enter the Arrival time of process: "<<endl;
    for(int i=0;i<n;i++)
    cin>>AT[i];
    cout<<"Enter the Burst time of process: "<<endl;
    for(int i=0;i<n;i++)
    cin>>BT[i];

    int s=0;
    for(int i=0;i<n;i++)
    {
        if(AT[i]<=s)
        s+=BT[i];
        else
        s=AT[i]+BT[i];
        CT[i]=s;
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-BT[i];
    }

    cout<<"CT TAT WT\n";
    for(int i=0;i<n;i++)
    cout<<CT[i]<<"  "<<TAT[i]<<"  "<<WT[i]<<endl;
}
