#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//dfs traversal ---------------------------------------------------------------------------------------
void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,set<int> > &adj,vector<int>&component){
    //answer stored
    component.push_back(node);
    //mark visited
    visited[node] = 1;
    //for all connected node recusive call
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i, visited, adj, component);
        }
    }
}
//function call ------------------------------------------------------------
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //Prepare adgecentsList
    unordered_map<int,set<int> > adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<vector<int>>ans;
    unordered_map<int,bool>visited;

    //for all nodes call dfs if not visited
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>>  edges = {{0 ,4},
                                  {2 ,0},
                                  {2 ,4},
                                  {3 ,0},
                                  {3 ,2},
                                  {4 ,3},
    };

    int v = 5;
    int e = 6;

    vector<vector<int>> ans = depthFirstSearch(v,e,edges);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
return 0;
}