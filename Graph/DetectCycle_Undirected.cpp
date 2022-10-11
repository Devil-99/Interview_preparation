#include<bits/stdc++.h>
using namespace std;

int V,E;

bool undirectedBFS(int node, vector<int>adj[], bool visited[]){
    queue<pair<int,int>>q;
    q.push({node,-1});
    visited[node]=true;

    while(!q.empty()){
        int curNode = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it:adj[curNode]){
            if(!visited[it]){
                visited[it]=true;
                q.push({it,node});
            }
            else{
                if(it!=parent)
                    return true;
            }
        }
    }
    return false;
}

bool undirectedDFS(int node,vector<int>adj[],bool visited[],int parent)
{
    visited[node]=true;
    for(auto it:adj[node])
    {
        if(!visited[it])
        {
           if(undirectedDFS(it,adj,visited,node))
           return true;
        }
        else if(it!=parent)
        return true;
    }
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
    if(undirectedDFS(node,adj,visited,-1))
    cout<<"Cycle Exist\n";
    else
    cout<<"Cycle doesn't exist\n";

return 0;
}
/*
6 8
0 1
1 2
3 5
3 0
4 3
4 0
5 6
6 4
*/