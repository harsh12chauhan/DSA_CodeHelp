#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
   
    vector<int> dist(n+1,1e9); 
    dist[src] = 0;

    // n-1 times
    for(int i=1;i<n;i++){
        //traverse on edge list
        for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            //formula of bellmonFord
            if(dist[u] != 1e9 && (dist[u]+ w < dist[v])){
                dist[v] = dist[u] + w;
            }
        }
    }

    //check cycle is present or not
    bool flag = false;
    for(int j=0;j<m;j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        
        //formula of bellmonFord
        if(dist[u] != 1e9 && (dist[u]+ w < dist[v])){
            flag = true;
        }
    }
    
    if(!flag){
        return dist[dest];
    }else{
        return -1;
    }
}
//bellmonford algorithm for finding shortest path with negative weights but not when -ve cycle is present ============
int main(){
vector<vector<int>> edges{{1, 2, 2},
                          {1, 3, 2},
                          {2, 3, -1}
};
int n = 3;
int m = 3;
int src = 1;
int dest = 3;
int ans = bellmonFord(n,m,src,dest,edges);
cout<<ans<<endl;
return 0;
}