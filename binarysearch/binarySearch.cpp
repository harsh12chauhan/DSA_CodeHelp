#include <iostream>
using namespace std;


int binarySearch(int arr[] ,int n ,int k){
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    while (start<=end)
    {
        if(arr[mid] == k){
            return mid;
        }

        if(k > arr[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){

    int arr[] = {2,5,7,9,12,45,57,79};
    int n = 8;
    int k = 11;
    int index = binarySearch(arr,n,k);
    cout<<index;
    
return 0;
}