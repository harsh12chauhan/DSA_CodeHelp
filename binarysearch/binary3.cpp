//find piovt in an array 
#include <iostream>
using namespace std;
int getPivotIndex (int arr[] ,int n){
    int start = 0;
    int end = n-1;
    int mid = start + ( end - start)/2;
    while(start<end){
       if(arr[mid] >= arr[0]){
            start = mid + 1;
        }else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}
int main(){
int arr[]={11,13,15,18,19,1,2,3,4,5};
int n = 10;
int pivotIndex = getPivotIndex(arr,n);
cout<<pivotIndex<<endl;
return 0;
}