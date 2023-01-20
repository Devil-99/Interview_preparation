// 1. Choose a single day to buy and different day to sell stock. Return the maximum profit.

#include <bits/stdc++.h>
using namespace std;

int buySell1(vector<int> prices)
{
    int mn=INT_MAX,ans=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mn)
                mn=prices[i];
            else if (prices[i]-mn>ans)
                ans=prices[i]-mn;
        }
        return ans;
}

int buySell2(vector<int>& prices) {
    int profit=0,buy=prices[0];
    for(int i=1;i<prices.size();i++){
        if(prices[i]>buy)
            profit+=prices[i]-buy;
        buy=prices[i];
    }
    return profit;
}

int main() {
    vector<int> prices={7,1,5,3,6,4};
    cout<<buySell1(prices)<<endl;
    cout<<buySell2(prices)<<endl;
    return 0;
}