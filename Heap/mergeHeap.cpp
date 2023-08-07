#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>&arr,int n,int index){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    
    if(left<n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right<n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,n,largest);
    }
}
//merge two binary max heap ----------------------------------------------------
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    
    vector<int> ans;
    
    for(int i = 0;i<n;i++){
        ans.push_back(a[i]);
    }
    for(int i = 0;i<m;i++){
        ans.push_back(b[i]);
    }
    
    int size = ans.size();
    for(int i = size/2-1;i>=0;i--){
        heapify(ans,size,i);
    }
    return ans;
}
int main(){
    vector<int> h1 = {10 ,5 ,6 ,2};
    vector<int> h2 = {12 ,7 ,9};
    int n1 = h1.size();
    int n2 = h2.size();
    
//merge two binary max heap====================================
    vector<int> ans = mergeHeaps(h1,h2,n1,n2);

//printing the merged binary max heap==========================
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
return 0;
}