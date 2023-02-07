#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>adj[], vector<int>color, int src){
    queue<int>q;
    q.push(src);
    color[src]=1;

    while(!q.empty()){
        int node= q.front();
        q.pop();

        for(auto it:adj[node]){
            if(color[it]==-1){
                q.push(it);
                color[it]=!color[node];
            }else if(color[it]==color[node]){
                return false;
            }
            
        }
        return true;
    }
return 0;
}

int main(){
    int n=8;
    vector<int>adj[8];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[4].push_back(7);
    adj[5].push_back(4);
    adj[5].push_back(6);
    adj[6].push_back(5);
    adj[6].push_back(1);
    adj[7].push_back(4);

    vector<int>color(n,-1);

    cout<<solve(adj,color,0);
return 0;
}