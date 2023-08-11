#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //preparing adjecent list
    unordered_map<int ,list<int> >adjList;
    for(int i=0;i<e;i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }
    //creating indegree 
    vector<int> inDegree(v);
    for(auto i:adjList){
        for(auto j:i.second){
            inDegree[j]++;
        }
    }

    //pushing 0 indegree values
    queue<int> q;
   for(int i = 0;i<v;i++){
       if(inDegree[i] == 0){
           q.push(i);
       }
   }

    vector<int> ans;
   
   //BFS
   while(!q.empty()){
       int node = q.front();
       q.pop();

        ans.push_back(node);

       for(auto neighbour:adjList[node]){
           inDegree[neighbour]--;
           if(inDegree[neighbour] == 0){
               q.push(neighbour);
           }
       }
   }
    
    return ans;
}
//TOPOLOGICAL SORT USING { BFS KAHN'S ALGO } IN (DAG)DIRECTED ACYCLIC GRAPH ===========
int main(){
vector<vector<int>>  edges = {{0 ,1},
                              {0 ,2},
    };

    int v = 3;
    int e = 2;
    //topological Sort ==========================
    vector<int> ans = topologicalSort(edges,v,e);

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
return 0;
}