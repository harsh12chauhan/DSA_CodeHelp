#include <iostream> 
#include <bits/stdc++.h> 
using namespace std;
bool isSafe(int x,int y,int n,vector<vector<int> >arr,vector<vector<int> > &visited){
    if((x>=0&&x<n)&&(y>=0 &&y<n)&&(arr[x][y] == 1) && visited[x][y] ==0){
        return true;
    }else{
        return false;
    }
}
void solve(vector<vector<int> >arr,vector<vector<int> > &visited,int n, int x,int y,string &path,vector<string>&ans){
        //base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;    
        
        //DLRU
        //down
        if(isSafe(x+1,y,n,arr,visited)){
            path.push_back('D');
            solve(arr,visited,n,x+1,y,path,ans);
            path.pop_back();
        }

        //left
        if(isSafe(x,y-1,n,arr,visited)){
            path.push_back('L');
            solve(arr,visited,n,x,y-1,path,ans);
            path.pop_back();
        }
        
        //right
        if(isSafe(x,y+1,n,arr,visited)){
            path.push_back('R');
            solve(arr,visited,n,x,y+1,path,ans);
            path.pop_back();
        }

        //up
        if(isSafe(x-1,y,n,arr,visited)){
            path.push_back('U');
            solve(arr,visited,n,x-1,y,path,ans);
            path.pop_back();
        }
        
        visited[x][y] = 0;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    if(arr[0][0] == 0){
        return ans;
    }
    vector<vector<int>> visited = arr;
        
        //initilized visited with zero
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                visited[i][j] = 0;
            }
        }    
    string path = "";
    solve(arr,visited,n,0,0,path,ans);
    return ans;
}
int main(){
    vector<vector<int> >arr = {{1,0,0,0},
                              {1,1,0,1},
                              {1,1,0,0},
                              {0,1,1,1},};
    int n = 4;
    vector<string> ans = searchMaze(arr,n);
    for(auto i:ans){
        cout<<i<<endl;
    }
    
    return 0;
}