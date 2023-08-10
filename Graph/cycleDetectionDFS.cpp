#include <iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

//function for checking if cycle is present in graph or not-----------------------------------------
bool isCyclic( unordered_map<int,list<int> > &adjList,unordered_map<int ,bool> &visited,int parent ,int node){
    
    visited[node] = 1;
    for(auto neighbour:adjList[node]){
       if(!visited[neighbour]){
            bool ans = isCyclic(adjList,visited,node,neighbour);
            if(ans){
                return true;
            }
        }else if(neighbour != parent){
                return true;
        }
    }
    return false;    
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int> > adjList;
    for(int i = 0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //To handle disconnected graph
    unordered_map<int ,bool> visited;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclic(adjList,visited,-1,i);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}
int main(){
vector<vector<int> > edges = {{0,3},
                              {0,2},
                              {3,1},
                              {2,4},
                              {4,1},
/*
n=3,m=6
{1 ,2},
{2 ,3}
*/
};
int n = 5;
int m = 6;
// cycle detection using DFS Traversal =======
string ans = cycleDetection(edges,n,m);
cout<<ans<<endl;
return 0;
}
