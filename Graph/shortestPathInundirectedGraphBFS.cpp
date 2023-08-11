#include <iostream>
#include<unordered_map>
#include<list>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int s , int t){
	
	unordered_map<int ,list<int> > adjList;
	for(int i=0;i<edges.size();i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	unordered_map<int ,bool> visited;
	unordered_map<int ,int> parent;

	queue<int> q;
	q.push(s);
	parent[s] = -1;
	visited[s] = 1;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto neighbour:adjList[front]){
			if(!visited[neighbour]){
				visited[neighbour] = 1;
				parent[neighbour] = front;
				q.push(neighbour);
			}
		}
	}

	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);

	while(currentNode != s){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
vector<pair<int,int>> edges = {{1 ,8},                               
                               {1 ,2},                               
                               {1 ,3},                               
                               {1 ,4},                               
                               {2 ,5},                                
                               {5 ,8}, 
                               {3 ,8},
                               {4 ,6},                               
                               {6 ,7},                                                             
                               {7 ,8}
};
int n = 8;
// SHORTEST PATH IN UNDIRECTED GRAPH using BFS  =======
vector<int> ans = shortestPath(edges,n,1,8);
for(auto i:ans){
    cout<<i<<" ";
}
cout<<endl;
return 0;
}