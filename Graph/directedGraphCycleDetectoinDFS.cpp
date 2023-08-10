#include <iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

//function for checking if cycle is present in directed graph or not-----------------------------------------
bool isCyclic(  unordered_map<int,list<int> > &adjList,   unordered_map<int ,bool> &visited,unordered_map<int ,bool> &dfsvisited,int node){
  visited[node] = true;
  dfsvisited[node] = true;

  for(auto neighbour:adjList[node]){
      if(!visited[neighbour]){
        bool cycleDetected = isCyclic(adjList, visited, dfsvisited,neighbour);
        if(cycleDetected){
          return true;
        }
      }else if(dfsvisited[neighbour]){
        return true;
      }
  }
  dfsvisited[node] = 0;
  return false;
}
//
int detectCycleInDirectedGraph(int n, vector<pair<int,int> > &edges) {
    
    //Prepare adgecentsList
    unordered_map<int,list<int> > adjList;
    for(int i = 0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    //To handle disconnected graph
    unordered_map<int ,bool> visited;
    unordered_map<int ,bool> dfsvisited;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclic(adjList,visited,dfsvisited,i);
            if(ans){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
vector<pair<int,int>> edges = {{1,2},
                               {4,1},
                               {2,4},
                               {3,4},
                               {5,2},
                               {1,3}                                
};
int n = 5;
int m = 6;
// cycle detection of DIRECTED GRAPH using DFS Traversal =======
int ans = detectCycleInDirectedGraph(n,edges);
cout<<ans<<endl;
return 0;
}