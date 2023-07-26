//peak index in an mountain array
#include <iostream>
using namespace std;
int peakEle(int arr[] ,int n ){
    int s=0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while (s<e)
    {
        if (arr[mid] < arr[mid + 1]){
            s = mid + 1;
        }else{
            e = mid;
        }

        mid = s + (e-s) /2;
    }
    return arr[s];
}
int main(){
int arr[] = {2,5,7,8,10,11,12,34,27,6,3,1};
int n = 8;
int peakElement = peakEle(arr,n);
cout<<" the peak element is : "<<peakElement<<endl;
return 0;
}