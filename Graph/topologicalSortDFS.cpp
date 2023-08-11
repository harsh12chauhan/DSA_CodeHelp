#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void topoSort(int node, unordered_map<int ,list<int> >&adjList,vector<bool> &visited,stack<int> &s){
    visited[node] = 1;

    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            topoSort(neighbour,adjList,visited,s);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int ,list<int> >adjList;
    for(int i=0;i<e;i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for(int i = 0;i<v;i++){
        if(!visited[i]){
            topoSort(i,adjList,visited,s);
        }
    }
    
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
//TOPOLOGICAL SORT USING DFS IN (DAG)DIRECTED ACYCLIC GRAPH ===========
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
    //topological Sort ==========================
    vector<int> ans = topologicalSort(edges,v,e);

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
return 0;
}