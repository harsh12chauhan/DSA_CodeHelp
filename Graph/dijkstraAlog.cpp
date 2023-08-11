#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //prepare adjecent list
    unordered_map<int,list<pair<int,int>>> adjList;
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }
    // create and initilize distance vector
    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i] = INT_MAX;
    }
    //creation of set on basis of (distance node)
    set<pair<int,int>> st;
    dist[source] = 0;
    st.insert({0,source});

    while(!st.empty()){
        //fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int node = top.second;
        //remove top record now
        st.erase(st.begin());
        //traverse on neighbours
        for(auto neighbour:adjList[node]){
            if(nodeDistance + neighbour.second  < dist[neighbour.first]){
                auto record = st.find({dist[neighbour.first],neighbour.first});
                //if record found then erase it 
                if(record != st.end()){
                    st.erase(record);
                }
                //distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                //record push in set
                st.insert({dist[neighbour.first],neighbour.first});
            }
        }
    }
return dist;
}

int main(){
vector<vector<int>> vec = {{0,1,7},
                           {0,2,1},
                           {0,3,2},
                           {1,2,3},
                           {1,3,5}, 
                           {1,4,1},
                           {3,4,7}
};
int n = 5;
int m = 7;
vector<int> ans = dijkstra(vec,n,m,0);
for(auto i:ans){
    cout<<i<<" ";
}
cout<<endl;
return 0;
}