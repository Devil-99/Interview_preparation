#include <iostream>
#include <map>

using namespace std;

string minWindow(string s, string t) {
    map<char,int>mp;
    for(auto c:t)
        mp[c]++;
    int low=0,count=t.size(),start=0,ans=INT_MAX;
    for(int high=0;high<s.length();high++){
        if(mp[s[high]]>0)
            count--;
        mp[s[high]]--;
        
        while(count==0){
            mp[s[low]]++;
            if(ans>high-low+1){
                ans=high-low+1;
                start=low;
            }

            if(mp[s[low]]>0)
                count++;
            low++;
        }
    }
    return ans==INT_MAX?"":s.substr(start,ans);
}

int main(){
string s="ADOBCODEBANC";
string t="ABC";
cout<<minWindow(s,t)<<endl;

return 0;
}