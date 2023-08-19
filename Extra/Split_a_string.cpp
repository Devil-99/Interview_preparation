// You are given a string s.

// A split is called good if you can split s into two non-empty strings sleft and sright 
// where their concatenation is equal to s (i.e., sleft + sright = s) 
// and the number of distinct letters in sleft and sright is the same.

// Return the number of good splits you can make in s.

#include <bits/stdc++.h>
using namespace std;

int numSplits(string s) {
    int n=s.length();
    vector<int>prefix(n),suffix(n);
    set<char>s1,s2;
    for(int i=0;i<n;i++){
        s1.insert(s[i]);
        s2.insert(s[n-1-i]);
        prefix[i]=s1.size();
        suffix[n-1-i]=s2.size();
    }
    int ans=0;
    for(int i=1;i<n;i++){
        if(prefix[i-1]==suffix[i]){
            cout<<i<<endl;
            ans++;
        }
    }
    return ans;
}

int main() {
    string s="aacaba";
    cout<<numSplits(s)<<endl;
    return 0;
}