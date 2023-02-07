#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            string s="";
            for(int j=0;j<strs[i].length();j++){
                if(ans[j]==strs[i][j])
                    s+=ans[j];
                else
                    break;
            }
            ans=s;
        }
        return ans;
    }

int main(){
vector<string> v={"flower","flow","flight"};
cout<<longestCommonPrefix(v);
return 0;
}