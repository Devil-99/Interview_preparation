#include<bits/stdc++.h>
using namespace std;

int V,E;

bool detectCycleUndirected(int node,vector<int>adj[],bool visited[],int parent)
{
    visited[node]=true;
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
           if(detectCycleUndirected(it,adj,visited,node))
           return true;
        }
        else if(it!=parent)
        return true;
    }
    return false;
}

bool detectCycleDirected(int node,vector<int>adj[],bool visited[],bool recVisited[])
{
    if(visited[node]==false)
    {
        visited[node]=true;
        recVisited[node]=true;
        for(auto it:adj[node])
        {
        if(!visited[it])
        {
           if(detectCycleDirected(it,adj,visited,recVisited))
           return true;
        }
        else if(recVisited[node]==true)
        return true;
        }
    }
    visited[node]=false;
    return false;
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

    //detect cycle
    int node;  //starting node
    cout<<"Enter the starting node"<<endl;
    cin>>node;

    bool visited[V]={false};
    bool recVisited[V]={false};

    // detect cycle in undirected graph
    if(detectCycleUndirected(node,adj,visited,node))
    cout<<"Cycle Exist\n";
    else
    cout<<"Cycle doesn't exist\n";

    // detect cycle in directed graph
    if(detectCycleDirected(node,adj,visited,recVisited))
    cout<<"Cycle Exist in the directed graph\n";
    else
    cout<<"Cycle doesn't exist in the directed graph\n";

return 0;
}
/*
6 7
0 1
1 2
3 5
3 0
4 3
4 0
5 6
6 4
*/