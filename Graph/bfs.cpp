#include<bits/stdc++.h>
using namespace std;

void bfs(int x,int V, vector<int>adj[],bool visited[])
{
    queue <int> q;
    q.push(x);
    visited[x]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it]=true;
                q.push(it);
            }
        }
    }
    cout<<endl;
    return;
}

int main()
{
    int V,E;
    cout<<"Enter the number of nodes and number of edges :- ";
    cin >> V >> E ;
    vector <int> adj[V];
    bool visited[V]={false};

    for(int i=0;i<E;i++)
    {
        int u,v;
        cout<<"Enter the edges ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);     //for unidirectional or directed graph this line shuld be ommited
    }

    // Example
    // V=7;E=6;
    // adj[0].push_back(1);
    // adj[1].push_back(2);
    // adj[1].push_back(6);
    // adj[2].push_back(4);
    // adj[4].push_back(6);
    // adj[3].push_back(5);

    //BFS
    int x;  //starting node
    cout<<"Enter the starting node"<<endl;

    // If there is any disconnected graph, then you need to run a loop for all non-visited vertices.
    // If there is only a single connected graph then you don't need to run a loop, just run the BFS once for any vertex(x).
    for(int i=0;i<V;i++){
        if(visited[i]==0)
            bfs(i,V,adj,visited);
    }
        
return 0;
}