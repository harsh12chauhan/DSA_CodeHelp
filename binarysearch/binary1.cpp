// first and last elements in an sorted array
#include <iostream>
using namespace std;

int firstoccurance(int arr[] ,int n, int k){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s) /2;
    int ans  = -1;
    while(s<=e){
        if(arr[mid] == k){
            ans = mid;
            e = mid - 1;
        }
        if(k > arr[mid]){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int lastroccurance(int arr[] ,int n, int k){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s) /2;
    int ans  = -1;
    while(s<=e){
        if(arr[mid] == k){
            ans = mid;
            s = mid + 1;
        }else if(k > arr[mid]){
            s = mid + 1;
        }else if(k < arr[mid]){
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

pair<int,int> firstanslastocc(int arr[], int n ,int k){
    pair<int,int> p;
    p.first = firstoccurance(arr,n,k);
    p.second = lastroccurance(arr,n,k);
    return p;
}

int main(){
int arr[] = {0,1,2,3,6,7,7,7,7,8,9};
int n = 11;
int k = 2123;
pair<int,int> v  = firstanslastocc(arr,n,k);;
cout<<"first occurance : "<<v.first<<endl;
cout<<"last occurance : "<<v.second<<endl;



return 0;
}