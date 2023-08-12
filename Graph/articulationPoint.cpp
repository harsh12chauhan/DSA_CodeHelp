#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

int min(int a ,int b){
    if(a > b){
        return b;
    }else{
        return a;
    }
}

void dfs(int node,unordered_map<int,list<int>> &adjList,vector<int> &disc,vector<int> &low,unordered_map<int,bool> &visited,vector<int> &ap,int timer,int parent){
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(auto nbr:adjList[node]){
        if(nbr == parent){
            continue;
        }
        if(!visited[nbr]){
            dfs(nbr,adjList,disc,low,visited,ap,timer,node);
            low[node] = min(low[node],low[nbr]);

            //check ap or not
            if(low[nbr] >= disc[node] && parent != -1){
                ap[node]=1;
            }child++;
        }else{
            //back edge
            low[node]  = min(low[node],disc[nbr]);
        }
        if(parent == -1 && child > 1){
            ap[node] = 1;
        }
    }
}
// articulation point in a graph using DFS ===================================================================
int main(){
int n = 5;
int e = 5;
vector<pair<int,int>> edges;
edges.push_back({0,3});
edges.push_back({3,4});
edges.push_back({0,4});
edges.push_back({0,1});
edges.push_back({1,2});

unordered_map<int,list<int>> adjList;
for(int i=0;i<edges.size();i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int timer=0;
vector<int> disc(n);
vector<int> low(n);
unordered_map<int,bool> visited;
vector<int> ap(n,0);
int parent = -1;

for(int i=0;i<n;i++){
    disc[i] = -1;
    low[i] = -1;
}

for(int i=0;i<n;i++){
    if(!visited[i]){
        dfs(i,adjList,disc,low,visited,ap,timer,parent);
    }
}
for(int i=0;i<n;i++){
    if(ap[i] != 0){
        cout<<i<<" ";
    }
}
cout<<endl;
return 0;
}