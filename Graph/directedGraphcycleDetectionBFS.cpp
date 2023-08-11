#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    //preparing adjecent list
    unordered_map<int ,list<int> >adjList;
    for(int i=0;i<edges.size();i++) {
        int u = edges[i].first-1;
        int v = edges[i].second-1;

        adjList[u].push_back(v);
    }
    //creating indegree 
    vector<int> inDegree(n);
    for(auto i:adjList){
        for(auto j:i.second){
            inDegree[j]++;
        }
    }

    //pushing 0 indegree values
    queue<int> q;
   for(int i = 0;i<n;i++){
       if(inDegree[i] == 0){
           q.push(i);
       }
   }

  int count = 0;
   
   //BFS
   while(!q.empty()){
       int node = q.front();
       q.pop();

        count++;

       for(auto neighbour:adjList[node]){
           inDegree[neighbour]--;
           if(inDegree[neighbour] == 0){
               q.push(neighbour);
           }
       }
   }
    
    if(count != n){
      return 1;
    }else{
      return 0;
    }
}
//CYCLE DETECTION USING { BFS KAHN'S ALGO } ==========================================
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