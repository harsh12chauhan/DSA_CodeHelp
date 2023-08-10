#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//printing the adjecents ------------------------------------------------------
void printAdjecent(unordered_map<int ,set<int> > adj){
    for(auto i:adj){
       cout<<i.first<<" -> ";
       for(auto j:i.second){
           cout<<j<<" ";
       }
       cout<<endl;
    }
}
//mapping node to their connected members -----------------------------------------
void getAdjecents(unordered_map<int ,set<int> > &adj,vector<vector<int> > edges){
    for(int i = 0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }
}
//bfs traversal ------------------------------------------------------------------
void bfs(unordered_map<int ,set<int> > &adj,unordered_map<int ,bool> &visited,vector<int> &ans,int node){

    queue<int>q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        //get the front node
        int frontNode = q.front();
        //remove the node from queue
        q.pop();
        // adding node to answer vector
        ans.push_back(frontNode);
        // adding the member node of frontNode to queue if they are not already present in queue
        for(auto i:adj[frontNode]){
            if(!visited[i]){
            q.push(i);
            visited[i] = 1;
            }
        }
    }
}
//function call -----------------------------------------------------------------------
vector<int> BFS(int vertex,vector<vector<int> > edges){
    unordered_map<int ,set<int> > adj;
    vector<int> ans;
    unordered_map<int ,bool> visited;

    getAdjecents(adj,edges);
    // printAdjecent(adj);

    for(int i = 0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }

    return ans;
}
int main(){
vector<vector<int> > edges = {
        {0,3},
        {0,2},
        {3,1},
        {2,4},
        {4,1},
};
int vertex = 5;

vector<int> ans = BFS(vertex,edges);
for(auto i:ans){
    cout<<i<<" ";
}
cout<<endl;
return 0;
}