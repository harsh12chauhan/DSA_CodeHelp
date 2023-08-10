#include <iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;
//function for checking if cycle is present in graph or not-----------------------------------------
bool isCyclic( unordered_map<int,list<int> > &adjList,unordered_map<int ,bool> &visited,int src){
   
    unordered_map<int,int> parent;

    parent[src] = -1;

    queue<int> q;
    q.push(src);
    
    visited[src] = 1;

    while(!q.empty()){
        //get the front node
        int front = q.front();
        q.pop();

        for(auto neighbour:adjList[front]){
            //checking  if visited is true and node is not equal to parent for cycle detection
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;    
}

//function call------------------------------------------------
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //Prepare adgecentsList
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
            bool ans = isCyclic(adjList,visited,i);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}
int main(){
    vector<vector<int> > edges = {
        {0,3},
        {0,2},
        {3,1},
        {2,4},
        {4,1},
};
int n = 5;
int m = 6;
string ans = cycleDetection(edges,n,m);
cout<<ans<<endl;
return 0;
}