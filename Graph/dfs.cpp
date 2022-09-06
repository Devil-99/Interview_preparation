#include<bits/stdc++.h>
using namespace std;

int V,E;

void dfs(int node,vector<int>adj[],bool visited[])
{
    visited[node]=true;
    cout<<node<<" ";
    for(auto it:adj[node])
    {
        if(!visited[it])
        dfs(it,adj,visited);
    }
    return;
}

int main()
{
    cin >> V >> E ;
    vector <int> adj[V];

    //for bi-directional graph
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);     //for unidirectional this line shuld be ommited
    }

    //BFS
    int node;  //starting node
    cout<<"Enter the starting node"<<endl;
    cin>>node;
    bool visited[V]={false};
    dfs(node,adj,visited);
    cout<<endl;

return 0;
}
/*
6 8
0 1
0 2
1 3
1 4
2 4
3 4
3 5
5 4
*/