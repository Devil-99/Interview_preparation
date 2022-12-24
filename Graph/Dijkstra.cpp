#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<pair<int,int>> adj[], int source){
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int>dist(v);
    for(int i=0;i<v;i++) dist[i]=1e9;

    dist[source]=0;
    pq.push({0,source});

    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto it:adj[node]){
            int nextNode=it.first;
            int edgeWeight=it.second;
            
            if(dis+edgeWeight < dist[nextNode]){
                dist[nextNode]=dis+edgeWeight;
                pq.push({dist[nextNode],nextNode});
            }
        }
    }
    return dist;
}

int main() {
    int v=6,source=0;
    vector<pair<int,int>> adj[v];
    adj[0].push_back({1,4});
    adj[0].push_back({2,4});
    adj[1].push_back({0,4});
    adj[1].push_back({2,2});
    adj[2].push_back({0,4});
    adj[2].push_back({1,2});
    adj[2].push_back({3,3});
    adj[2].push_back({4,1});
    adj[2].push_back({5,6});
    adj[3].push_back({2,3});
    adj[3].push_back({5,2});
    adj[4].push_back({2,1});
    adj[4].push_back({5,3});
    adj[5].push_back({2,6});
    adj[5].push_back({3,2});
    adj[5].push_back({4,3});

    vector<int>ans;
    ans=dijkstra(v,adj,source);

    for(auto it:ans)
    cout<<it<<" ";
    cout<<endl;

    return 0;
}