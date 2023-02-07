// A mobile keypad has 9 buttons where each button can have upto 3 english letter.
// The buyer has the freedom to choose which letters to place on a button while ensuring that the arrangement is valid.
// A keypad design is said to be valid if: - All 26 letters of the English alphabet exist on the keypad, Each letter is mapped to exactly one button.
// Return min no of keyPress to type a string.
// Question Link - https://leetcode.com/discuss/interview-question/2464743/amazon-oa-2022

#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    map<char,int> mp;
    for(auto c:s)
    mp[c]++;

    vector<int>v;
    for(auto it:mp)
    v.push_back(it.second);

    sort(v.rbegin(), v.rend());

    int ans=0,i=0;
    while(i<v.size()){
        if(i<9){
            ans+=v[i];
        }
        else if(i<18){
            ans+= 2*v[i];
        }
        else{
            ans+= 3*v[i];
        }
        i++;
    }
    return ans;
}

int main(){
string s="abcdefghabef";
cout<<solve(s)<<endl;;
return 0;
}