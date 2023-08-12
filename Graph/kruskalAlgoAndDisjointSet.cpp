#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int>&a,vector<int>&b){
    return a[2] < b[2];
}
//initilization of parent and rank vector -----------------------------
void makeset(vector<int>&parent,vector<int>&rank,int n){
    for(int i = 0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
//function for finding parent ------------------------------------------
int findParent(vector<int>&parent,int node){
    if(parent[node] == node){
        return node;
    }
    //( parent[node] ) <-  written for path compression
    return parent[node] = findParent(parent,parent[node]);
}
//function for union of two nodes -------------------------------------
void unionSet(vector<int>&parent,vector<int>&rank,int u,int v){
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[v] < rank[u]){
        parent[v] = u;
    }else{
        parent[u] = v;
        rank[v]++;
    }
}
//function call -------------------------------------------
int minimumSpanningTree(vector<vector<int>>&edges,int n){

    sort(edges.begin(),edges.end(),comp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent,rank,n);
    int minWt = 0;
    for(int i=0;i<n;i++){
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        int wt = edges[i][2];

        if(u != v){
            minWt += wt;
            unionSet(parent,rank,u,v);
        }
    }
    return minWt;
}
//MINIMUM SPANNING TREE (DISJOINTSET AND KRUSKAL'S ALGORITHM) ===========================
int main(){
vector<vector<int>>edges = {{1, 2, 6},
                            {2, 3, 2},
                            {1, 3, 2},
                            {1, 0, 2}
};
int n = 4;
int ans = minimumSpanningTree(edges,n);
cout<<ans<<endl;


return 0;
}