#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int,list<pair<int,int> > > adjList;

    void addAdj(int u,int v,int w){
        adjList[u].push_back({v,w});
    }

    void printAdjecent(){
        for(auto i:adjList){
        cout<<i.first<<" -> ";
        for(auto j:i.second){
            cout<<"("<<j.first<<","<<j.second<<"),";
        }
        cout<<endl;
        }
    }

    // =========================================================
    void topoSort(int node,vector<bool> &visited,stack<int> &s){
        visited[node] = 1;

        for(auto neighbour:adjList[node]){
            if(!visited[neighbour.first]){
                topoSort(neighbour.first,visited,s);
            }
        }
        s.push(node);
    }
    void shortestPath(int src,vector<int> &dist,stack<int> &s){
        dist[src]=0 ;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(dist[top] != INT_MAX){
                for(auto i:adjList[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;   
                    }
                }
            }
        }
    }
};
// SHORTEST PATH IN WEIGHTED DIRECTED GRAPH using DFS  =======
int main(){
    graph g;
    g.addAdj(0,2,3);
    g.addAdj(1,2,2);
    g.addAdj(1,3,6);
    g.addAdj(2,3,7);
    g.addAdj(2,4,4);
    g.addAdj(2,5,2);
    g.addAdj(3,4,-1);
    g.addAdj(4,5,-2);

    g.printAdjecent();

    //topological sort
    int n = 6;

    vector<bool> visited(n);
    stack<int> s;

    for(int i =0;i<n;i++){
        if(!visited[i]){
            g.topoSort(i,visited,s);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for(int i = 0;i<n;i++){
        dist[i] = INT_MAX;
    }

    g.shortestPath(src,dist,s);

    for(int i = 0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

return 0;
}