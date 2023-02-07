#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(){
        left=NULL;
        right=NULL;
    }
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


void adjacency(Node* node,int parent,unordered_map<int,vector<int>>& adj)
{
    if(parent!=-1)
        adj[node->data].push_back(parent);
    if(node->left){
        adj[node->data].push_back(node->left->data);
        adjacency(node->left,node->data,adj);
    }
    if(node->right){
        adj[node->data].push_back(node->right->data);
        adjacency(node->right,node->data,adj);
    }
    return;
}

void burn(unordered_map<int,vector<int>> adj, int target, map<int,int>&vis){
    queue<int>q;
    q.push(target);
    
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            int node=q.front();
            vis[node]=1;
            cout<<node<<" ";
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]!=1)
                    q.push(it);
            }   
        }
        cout<<endl;
    }
}

int main()
{
    Node *root=new Node(12);
    root->left=new Node(19);
    root->right=new Node(82);
    root->left->left=new Node(41);
    root->left->left->right=new Node(2);
    root->right->left=new Node(15);
    root->right->right=new Node(95);
    root->right->left->left=new Node(21);
    root->right->right->left=new Node(7);
    root->right->right->right=new Node(16);

    int target=41;

    unordered_map<int,vector<int>> adj;
    adjacency(root,-1,adj);

    map<int,int>vis;
    burn(adj,target,vis);
    return 0;
}