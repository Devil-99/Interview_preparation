#include<bits/stdc++.h>
using namespace std;

void printGraph(int V, vector<int>adj[])
{
    for(int i=0;i<V;i++)
    {
        cout<<i;
        for(auto it:adj[i])
        cout<<"->"<<it;
        cout<<endl;
    }
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
        adj[v].push_back(u);        //for unidirectional this line shuld be ommited
    }
printGraph(V,adj);

return 0;
}