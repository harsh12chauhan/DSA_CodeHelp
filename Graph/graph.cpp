#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>

class graph{
    public:
    unordered_map<T,list<T> > adj;

    void addAdjecent(T u,T v,bool direction){
        // direction  == 0 -> undirected graph
        // direction  == 1 -> directed graph

        //create an edge from u to v (u->v)
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjecent(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    cout<<"Enter number of nodes :";
    int n;
    cin>>n;
    cout<<"Enter number of edges :";
    int m;
    cin>>m;

    graph<int> g;
    cout<<"Enter the edges :->"<<endl;   
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addAdjecent(u,v,0);
    }

    //printing graph
    g.printAdjecent();

return 0;
}


/*
n = 5
m = 6
input edges
0 1
1 2
2 3
3 1
3 4
4 0
*/ 
