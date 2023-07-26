// search an element in an rotated sorted array
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr,int s, int e, int k){
    int start = s;
    int end = e;
    int mid = start + ( end- start )/2;
    while(start<=end){
        if(k == arr[mid]){
            return mid;
        }
        if(k > arr[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + ( end-start )/2;
    }
    return -1;
}

int getPivot(vector<int>& arr, int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e -s)/2;
    while(s<e){
       if(arr[mid] >= arr[0]){
           s = mid + 1;
       }else{
           e = mid ;
       }
       mid  = s + (e -s)/2;
    }
    return s;
}

int search(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr,n);
    if(k >= arr[pivot] && k <= arr[n-1]){
        return binarySearch(arr,pivot,n,k);
    }else{
        return binarySearch(arr,0,pivot-1,k);
    }

}


int main(){
vector<int> arr = {11,13,15,18,19,1,2,3,4,5};
int n = 10;
int k = 12;
int value = search(arr,n,k);
if(value != -1){
    cout<<"value exist"<<endl;
}else{
    cout<<" value does not exist"<<endl;
} 
return 0;
}