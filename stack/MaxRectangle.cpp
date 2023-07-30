#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000
using namespace std;
 vector<int> nextSmallElement(vector<int> arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i =n-1;i>=0;i--){
        int crr = arr[i];

        while(s.top() != -1 && arr[s.top()]>=crr){
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
   return ans;
}
   vector<int> prevSmallElement(vector<int> arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i =0;i<n;i++){
        int crr = arr[i];

        while(s.top() != -1 && arr[s.top()]>=crr){
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
   return ans;
}
   int largestRectangleArea(vector<int> heights,int n) {
       vector<int> next(n);
       next = nextSmallElement(heights,n);
    
       vector<int> prev(n);
       prev = prevSmallElement(heights,n);
    
       int area = INT16_MIN;
    
       for(int i=0;i<n;i++){
         int l = heights[i];
         if(next[i] == -1){
            next[i] = n;
         }
         int b = next[i] - prev[i] - 1;
         int newArea = l*b;
         area = max(area,newArea);
        }
  return area;
 }

int maxArea(vector<vector<int>> M,int n, int m) {
    int area = largestRectangleArea(M[0],m);
    for(int i = 1;i<n;i++){
        for(int j = 0;j<m;j++){   
            //update row
            if(M[i][j] != 0){
                M[i][j] = M[i][j] + M[i-1][j];
            }else{
                M[i][j] = 0;
            }
        }
        area = max(area ,largestRectangleArea(M[i],m));
    }
    return area;        
}
int main(){
int n = 4;
int m = 4;
// problem when using normal array in place of this vector
vector<vector<int>> M ={{0, 1, 1, 0}, 
                        {1, 1, 1, 1},
                        {1, 1, 1, 1},
                        {1, 1, 0, 0}};

int value = maxArea(M,n,m);

std :: cout<<"Maximum area is : "<<value<<endl;
return 0;
}