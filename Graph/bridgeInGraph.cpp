#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int, list<int>> &adjList,vector<int> &disc,vector<int> &low,unordered_map<int,bool> &visited,int timer,int parent,vector<vector<int>> &result){
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto nbr:adjList[node]){
        if(nbr == parent){
            continue;
        }
        if(!visited[nbr]){
            dfs(nbr,adjList,disc,low,visited,timer,node,result);

            //update low
            low[node] = min(low[node],low[nbr]);

            //check if the crrent edge is bridge or not
            if(low[nbr] > disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }else{
            //node already visited and not parent
            //back edge
            low[node] = min(low[node],disc[nbr]);
        }
    }
}   
//function call -------------------------------------------------------
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
  unordered_map<int, list<int>> adjList;
  for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int,bool> visited;

    for(int i=0;i<v;i++){
        disc[i] = -1;
        low[i] = -1;
    }
    
    vector<vector<int>> result;

    for(int i =0;i<v;i++){
        if(!visited[i]){
            dfs(i,adjList,disc,low,visited,timer,parent,result);
        }
    }

    return result;

}
//Bridge in a Graph using DFS =========================================================
int main(){
vector<vector<int>> edges{{1,2},
                          {1,0},
                          {0,2},
                          {0,4},
                          {5,4},
                          {5,3},
                          {3,4}
};
int v=6;
int e=7;
vector<vector<int>> ans  = findBridges(edges,v,e);
 for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
return 0;
}