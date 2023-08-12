#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //crreate adjecency list
    unordered_map<int ,list<pair<int,int>>> adjList;
    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});        
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    
    for(int i =0;i<=n;i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    //lets start the algorithm
    key[1] = 0;
    parent[1] = -1;
    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        int u;
        //find the minimum node
        for(int v=1;v<=n;v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }
        // mark minimun node as true
        mst[u] = true;
        //check its adcent nodes
        for(auto it:adjList[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    //after parent vector is ready prepare answer from parent vector
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}
//minimum spanning tree using prims algorithm =================================================
int main(){
    vector<pair<pair<int, int>, int>> g={{ {1 ,2} ,2},
                                         { {1 ,4} ,6},
                                         { {2 ,1} ,2},
                                         { {2 ,3} ,3},
                                         { {2 ,4} ,8},
                                         { {2 ,5} ,5},
                                         { {3 ,2} ,3},
                                         { {3 ,5} ,7},
                                         { {4 ,1} ,6},
                                         { {4 ,2} ,8},
                                         { {4 ,5} ,9},
                                         { {5 ,2} ,5},
                                         { {5 ,3} ,7},
                                         { {5 ,4} ,9}
    };
    int n =5 ;
    int m = 14;
vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(n,m,g);
for(auto i:ans){
    cout<<"("<<i.first.first<<","<<i.first.second<<","<<i.second<<")"<<endl;   
}
return 0;
}