#include<bits/stdc++.h>
using namespace std;

int V,E;

bool directedDFS(int node,vector<int>adj[],bool visited[],bool recVisited[])
{
    visited[node]=true;
    recVisited[node]=true;
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            if(directedDFS(it,adj,visited,recVisited))
            return true;
        }
        else if(recVisited[it])
            return true;
    }
    recVisited[node]=false;
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
    }

    //detect cycle
    int node;  //starting node
    cout<<"Enter the starting node"<<endl;
    cin>>node;

    bool visited[V]={false};
    bool recVisited[V]={false};

    // detect cycle in directed graph
    bool flag=false;
    for(int i=1;i<V;i++){
        if(directedDFS(i,adj,visited,recVisited))
            flag=true;
    }

    if(flag)
    cout<<"Cycle Exist in the directed graph\n";
    else
    cout<<"Cycle doesn't exist in the directed graph\n";

return 0;
}

/*
10 10
1 2
2 3
3 4
4 5
3 6
6 5
7 2
7 8
8 9
9 7
*/