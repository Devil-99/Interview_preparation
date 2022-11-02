#include<bits/stdc++.h>
using namespace std;

int mx;

void largetsCycle(int node, vector<int>&edges, vector<int> &visited, vector<int> &length, int currLength)
{
    if(!visited[node]){
        visited[node]=1;
        length[node]=currLength;

        if(edges[node]!= -1)
            largetsCycle(edges[node],edges,visited,length,currLength+1);
        
        length[node]=-1;
    }
    else{
        if(length[node] != -1){
            mx= max(currLength-length[node],mx);
        }
    }
}

int maximumWeightedNode(vector<int>&edges){
    int ans=INT_MIN;
    int result =-1;
    vector<int>weight(edges.size(),0);

    for(int i=0;i<edges.size();i++){
        int source=i;
        int destination = edges[i];
        if(destination!=-1){
            weight[destination]+=source;
            if(ans<=weight[destination]){
                ans=max(weight[destination],ans);
                result=destination;
            }
        }
    }

    if(ans!=INT_MIN)
        return result;
    return -1;
}

void shortPath(vector<int>adj[], int c1, int n, vector<int>&dist){
    queue<int>q;
    q.push(c1);
    dist[c1]=0;

    while(!q.empty()){
        int temp=q.front();
        q.pop();

        for(auto &it:adj[temp]){
            if(dist[it]>dist[temp]+1){
                dist[it]=dist[temp]+1;
                q.push(it);
            }
        }
    }
}

int main()
{
    int n=23;
    vector<int>edges={4,4,1,4,13,8,8,8,0,8,14,9,15,11,-1,10,15,22,22,22,22,22,21};

    vector<int> visited(n,0),length(n,-1);

    for(int i=0;i<n;i++){
        if(!visited[i])
            largetsCycle(i,edges,visited,length,0);
    }
    cout<<"Longest cycle is "<<mx<<endl;

    cout<<"Maximum Weighted Node is "<<maximumWeightedNode(edges)<<endl;

    int c1=14,c2=16;
    vector<int> adj[n];
    for(int i=0 ; i<n ; i++){
        if(edges[i] == -1) continue;
        adj[i].push_back(edges[i]);
    }
    vector<int>v1(n,INT_MAX);
    vector<int>v2(n,INT_MAX);

    shortPath(adj, c1, n, v1);
    shortPath(adj, c2, n, v2);

    int mn = INT_MAX, node = -1;
    for(int i=0 ; i<n ; i++){
        if(v1[i] == INT_MAX || v2[i] == INT_MAX)
            continue;
        if(v1[i] + v2[i] < mn){
            mn = v1[i] + v2[i];
            node = i;
        }
    }
    cout <<"Nearest node from "<<c1<<" and "<<c2<<" is "<< node << endl;

return 0;
}
