#include<bits/stdc++.h>
using namespace std;

void bfs(int x,int V, vector<int>adj[])
{
    bool visited[V]={false};
    queue <int> q;
    q.push(x);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        visited[node]=true;
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
    int x;  //starting node
    cout<<"Enter the starting node"<<endl;
    cin>>x;
    bfs(x,V,adj);

return 0;
}