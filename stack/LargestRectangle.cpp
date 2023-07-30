#include <iostream>
#include <vector>
#include <stack>
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
 int largestRectangle(vector < int > & heights) {
   int n =heights.size();
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
int main(){
vector<int> a = {2,1,5,6,2,3};
int area = largestRectangle(a);
cout<<"largest rectangle in histogram is "<<area<<endl;
return 0;
}