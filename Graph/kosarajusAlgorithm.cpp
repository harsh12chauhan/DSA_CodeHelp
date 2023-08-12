#include <iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
using namespace std;
//dfs -------------------------------------------------------------------------------------
void dfs(int node,unordered_map<int,list<int>> &transpose,unordered_map<int,bool> &visited){
	visited[node] = true;
	for(auto nbr:transpose[node]){
		if(!visited[nbr]){
			dfs(nbr,transpose,visited);
		}
	}
}
//topological sort ------------------------------------------------------------------------------------------
void topoSort(int node,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,stack<int> &st){
	visited[node] =true;

	for(auto nbr:adjList[node]){
		if(!visited[nbr]){
			topoSort(nbr,adjList,visited,st);
		}
	}
	st.push(node);
}
//function call ---------------------------------------------------
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adjList;
	for(int i=0;i<edges.size();i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adjList[u].push_back(v);
	}

	unordered_map<int,bool> visited;
	stack<int> st;
	//topological sort 
	for(int i=0;i<v;i++){
		if(!visited[i]){
			topoSort(i,adjList,visited,st);
		}
	}

	// transpose
	unordered_map<int,list<int>> transpose;
	for(int i=0;i<v;i++){
		visited[i] = 0;
		for(auto nbr:adjList[i]){
			transpose[nbr].push_back(i);
		}
	}

	//dfs
	int count =0;
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!visited[top]){
			dfs(top,transpose,visited);
			count++;
		}
	}
	return count;
}
// Kosaraju algorithm for finding stronglly connected componends ==========================================  
int main(){
vector<vector<int>> edges{{0 ,1},
                          {1 ,2},
                          {1 ,4},
                          {2 ,3},
                          {3 ,2},
                          {4 ,0},
};
int v = 5;
int ans = stronglyConnectedComponents(v,edges);
cout<<ans<<endl;
return 0;
}