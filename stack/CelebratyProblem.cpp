#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool knows(vector<vector<int> >& M,int a,int b, int n){
        if(M[a][b] == 1){
            return true;
        }else{
            return false;
        }
}

int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i = 0;i<n;i++){
            s.push(i);
        }
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        int candidate = s.top();
        int zeroCnt = 0;
        for(int i = 0;i<n;i++){
            if(M[candidate][i] == 0){
                zeroCnt++;
            }
        }
        if(zeroCnt != n){
            return -1;
        }
        int oneCnt = 0;
        for(int i = 0;i<n;i++){
            if(M[i][candidate] == 1){
                oneCnt++;
            }
        }
        if(oneCnt != n-1){
            return -1;
        }
        return candidate;
}
int main(){
vector<vector<int>> M = {{0, 1, 0},
                         {0, 0, 0}, 
                         {0, 0, 0}};
int n = 3;
int val = celebrity(M,n);
if(val != -1){
    cout<<val<<" is the celebrity in the party !"<<endl;
}else{
    cout<<"no there is no celebrity in the party !"<<endl;
}
return 0;
}