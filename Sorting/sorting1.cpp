//selection sorting 

#include <iostream>
using namespace std;

int* selectionSort(int arr[],int n){
    for( int i =0;i<n;i++){
        int minIndex = i;
        for(int j = i+1;j<=n;j++){
            if (arr[j]< arr[minIndex] )
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
    return arr;
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
int arr[] = {2,4,7,9,87,654,32};
int n = 7;
int *a = selectionSort(arr,n);
display(a,n);
return 0;
}