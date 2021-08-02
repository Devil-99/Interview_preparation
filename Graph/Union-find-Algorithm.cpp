#include <bits/stdc++.h>
using namespace std;

int V,E;

// a class to represent a disjoint set
class Set {
    unordered_map <int,int> parent;
public:
    void Makeset(int v)
    {
        for(int i=0;i<v;i++)
        parent[i]=-1;
    }
    int Find(int k)
    {
        if(parent[k]==-1)
        return k;
        return Find(parent[k]);
    }
    void Union(int a,int b)
    {
        int x=Find(a);
        int y=Find(b);

        parent[x]=y;
    }
};

bool findCycle(vector<int>adj[])
{
    // initialise main class
    Set ds;
    ds.Makeset(V);

    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            int x=ds.Find(i);
            int y=ds.Find(it);

            if(x==y)
            return true;
            else
            ds.Union(x,y);
        }
    }
    return false;
}

int main()
{
    cin >> V >> E ;
    vector <int> adj[V];

    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    if(findCycle(adj))
    cout<<"Cycle Found\n";
    else
    cout<<"No Cycle Detected\n";
return 0;
}