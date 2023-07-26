#include <iostream>
using namespace std;

int sumOfArray(int arr[],int n){
    int sum =0;
    for(int i =0 ;i<n;i++){
       sum += arr[i];
    }
    return sum;
}

int main(){
    // int i = 5;
    // int& j = i;

    // cout<<"value of i: "<<i<<endl;
    // cout<<"value of j: "<<j<<endl;

    // j++;
    // cout<<"value of i: "<<i<<endl;
    // i--;
    // cout<<"value of i: "<<j<<endl;33

// dynamic memory allocation (using heap memory)================================

    // char* ch = new char;
    // *ch = 'a';
    // cout<<*ch<<endl;

    //array================
    // int n;
    // cout<<"enter the size of array: ";
    // cin>>n;
    // cout<<endl;

    // int* arr = new int[n];

    // cout<<"enter the values for array: ";
    // for(int i =0 ;i<n;i++){
    //     cin>>arr[i];
    // }
    // int sum = sumOfArray(arr,n);
    // cout<<"sum of the array is : "<<sum<<endl;

    // delete []arr;

    // int row;
    // cin>>row;

    // int col;
    // cin>>col;
    // //creation of the 2d array
    // int**arr = new int*[row];  //array of pointers 
    // for(int i = 0;i<row;i++){
    //     arr[i] = new int[col];  //arrays and assining it with pointers
    // }

    // //taking input 
    // for(int i =0;i<row;i++){
    //     for(int j =0;j<col;j++){
    //         cin>>arr[i][j];
    //     }
    // }

    // //taking output 
    // for(int i =0;i<row;i++){
    //     for(int j =0;j<col;j++){
    //         cout<<arr[i][j]<<" ";
    //     }cout<<endl;
    // }

    // //releaseing memory  
    // for(int i = 0;i<row;i++){
    //     delete [] arr[i];     //deleting arrays that are assigned to pointers array
    // }

    // delete []arr;   // deleting the array of pointers
    




return 0;
}