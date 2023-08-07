#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
      //code here
      priority_queue<int> pq;
      
      for(int i = 0;i<k;i++){
          pq.push(arr[i]);
      }
      
      for(int i = k;i<=r;i++){
          if(arr[i] < pq.top()){
              pq.pop();
              pq.push(arr[i]);
          }
      }
      
      int ans = pq.top();
      return ans;
}

int main(){
    int arr[6] = {4,5,2,6,1,8};
    int n = 6;
    int k = 3;
    int ans = kthSmallest(arr,0,n-1,k);
    cout<<"Kth smallest number is -> "<<ans<<endl;
}