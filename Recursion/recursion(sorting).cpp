#include <iostream>
#include <vector>
using namespace std;
//==================================================================
void printValues(int n){
    //base case
    if(n == 0)
        return;
    cout<<n<<endl; // prints   5 4 3 2 1 
    printValues(n-1);  // recursion relation 
    // cout<<n<<endl; // prints   1 2 3 4 5 
}
//==================================================================
int fact(int n){
    //base case
    if(n == 1)
        return 1;
    
    return n * fact(n-1);
}
//==================================================================
int power(int n,int p){
    if(p == 0)
        return n;
    
    return n * power(n ,p-1);
}
//==================================================================
int fibo(int a ,int b,int th){

    if(th == 1)
        return a+b;
    cout<< "value of a : b - "<<a<<" : "<<b<<endl;
    return  fibo(b,a+b,th-1);
}
//==================================================================
void sayDigit(int n,string s[]) {
        //base case
        if( n == 0)
            return;

        sayDigit(n/10,s);

        int val = n%10;
        cout<<s[val]<<" ";
    }
//==================================================================
bool isSorted(int arr[],int n){
    //base case
    if(n == 0||n == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }else{
        return isSorted((arr+1),n-1);
    }
}
//==================================================================
int sumOfArray(int arr[],int n){
    //base case
    if(n == 0)
        return 0;
    if(n == 1)
        return arr[0];

    return arr[0] + sumOfArray(arr+1,n-1);
}
//==================================================================
void print(int *arr,int n){
    cout<<"Size of the array is : "<<n<<endl;

    for(int i= 0;i<n;i++){
         cout<<arr[i]<<" "; 
    }
    cout<<endl;
}
//==================================================================
int linearSearch(int arr[],int n,int target,int i = 0){
    
    if(n == 0)
        return -1;
    //  print1(arr,n);
   
    if(arr[0] == target){
        return i;
    }else{
        return linearSearch(arr+1,n-1,target,i+1);
    }

}
//==================================================================
void binaryPrint(int arr[],int s,int e){
    for(int i = s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//==================================================================
int binarySearch(int arr[],int s,int e,int target){

    // binaryPrint(arr,s,e);
    if(s>e){
        return -1;
    }

    int mid = s+(e-s)/2;
    cout<<"value of mid: -> "<<arr[mid]<<endl;
    if(arr[mid] == target){
        return mid;
    }
    if(arr[mid] < target){
        return binarySearch(arr,mid+1,e,target);
    }else{
        return binarySearch(arr,s,mid-1,target);
    }
}
//==================================================================
void reverseString(string &s,int i,int j){   //  second pointer(j) = n-i-1 <-think

    cout<<"value(s) inside func "<<s<<endl;
   if(i>j)            
        return ;
        
    swap(s[i++],s[j--]);
   reverseString(s,i,j);
}
//==================================================================
bool plaindrome(string s,int i,int j){
    if(i>j)
        return true;

    if(s[i] != s[j]){
        return false;
    }else{
        return plaindrome(s,i+1,j-1);
    }
}
//==================================================================
int powerByFormula(int a,int b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    
    int ans = powerByFormula(a,b/2);

    if((b%2) == 0){
        return ans * ans;
    }else{
        return a * ans * ans;
    }
}
//==================================================================
void bubbleSort(int arr[],int n){
    // cout<<"before "<<endl;
    // print(arr,n);

    if(n == 0 || n == 1)
        return;
    
    for(int i = 0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    // cout<<"after "<<endl;
    // print(arr,n);cout<<endl;

    bubbleSort(arr,n-1);
}
//==================================================================
void selectionSort(int arr[],int n){

    // cout<<"before "<<endl;
    // print(arr,n);

    if(n ==0 || n == 1)
        return;

    int i = 0;
    for(int j = i;j <n ;j++){
        if(arr[i] > arr[j]){
            swap(arr[i],arr[j]);
        }
    }

    // cout<<"after "<<endl;
    // print(arr,n);cout<<endl;

    selectionSort(arr+1,n-1);
}
//==================================================================
void insertionSort(int arr[],int n){

    if(n == 0 || n == 1)
        return ;

    for(int i = 1;i<n;i++){
        int temp = arr[i];
        for(int j = i-1;j>=0;j--){
            if(temp < arr[j]){
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // insertionSort(arr,n);
}
//==========================================================================
void merge(int arr[],int s,int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    //copy the elements in new arrays
    int mainIndex = s;
    for(int i =0;i<len1;i++){
        arr1[i] = arr[mainIndex++];
    }

    mainIndex = mid + 1;
    for(int i =0;i<len2;i++){
        arr2[i] = arr[mainIndex++];
    }

    // merge two sorted array logic
    int index1 = 0;
    int index2 = 0;
    mainIndex = s;
    while(index1 < len1 && index2 < len2){
        if(arr1[index1] >arr2[index2]){
            arr[mainIndex++] = arr2[index2++];
        }else{
            arr[mainIndex++] = arr1[index1++];
        }
    }

    while(index1 < len1){
        arr[mainIndex++] = arr1[index1++];
    }

    while(index2 < len2){
        arr[mainIndex++] = arr2[index2++];
    }

    delete [] arr1;
    delete [] arr2;
}
void mergeSort(int arr[],int s,int e){

    cout<<"before "<<endl;
    binaryPrint(arr,s,e);

    if(s>=e)
        return;

    int mid = s + (e-s)/2;

    //left part
    mergeSort(arr,s,mid);

    //right part
    mergeSort(arr,mid+1,e);

    //merge array 
    merge(arr,s,e);

    cout<<"after "<<endl;
    binaryPrint(arr,s,e);
    
}
//========================================================================
int partition(int arr[],int s,int e){
    int pivot = arr[s];   

    int count = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    //place pivot at right position
    int pivotIndex = s + count; 
    swap(arr[pivotIndex],arr[s]);

    // left and right part (smallValue < pivot > largeValue)
    int i = s;
    int j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;
}
void quickSort(int arr[],int s,int e){
    // cout<<" before : "<<endl;
    // binaryPrint(arr,s,e);

    if(s>=e)
        return ;
    
    int p = partition(arr,s,e);
    //left part
    quickSort(arr,s,p-1);

    //right part
    quickSort(arr,p+1,e);

    // cout<<" after : "<<endl;
    // binaryPrint(arr,s,e);
    // cout<<endl;
}
//===============================================================
 void getSubset(vector<int> nums,vector<int>output,int index,vector<vector<int>> &ans){
        //base case
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude
        getSubset(nums,output,index+1,ans);

        //include
        int element = nums[index];
        output.push_back(element);
        getSubset(nums,output,index+1,ans);

    }
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        cout<<"ret"<<endl;
        getSubset(nums,output,index,ans);
        cout<<"returning :: ?>/"<<endl;
        return ans;
    }
int main(){

// RECURSION ================================================================
    // int n =2;
    //printing n elements===================
    // printValues(n);

    //factorial=============================
    // int value = fact(n);
    // cout<<"Factorial of :"<<n<<" is ->"<<value<<endl;

    //power of number=======================
    // int p = 2;
    // int value = power(n,p);
    // cout<<"Answer of "<<n<<" to the power "<<p<<" is -> "<<value<<endl;

    //Fibonacci series =====================
    // int a = 0;
    // int b = 1;
    // int th = 8;
    // int value = fibo(a,b,th-2);
    // cout<<"the value of 8th element in fibonacci series is : ->  "<<value<<endl;


//Question --> say digits=================================
    // int n ;
    // cout<<"enter number to say: ";
    // cin>>n;
    // cout<<endl;
    // string arr[10] = {"zero","one","two",
    //                 "three","four","five",
    //                 "six","seven","eight","nine"};
    // sayDigit(n,arr);

//Question --> array is sorted or not=====================
    // int arr[5] = {1,1,1,1,1};
    // int n = 5;
    // if(isSorted(arr,n)){
    //     cout<<"Sorted !!"<<endl;
    // }else{
    //     cout<<"Not Sorted "<<endl;
    // }

//Question sum of array ==================================
    // int arr[8] = {1,2,3,4,5,5,4,6};
    // int n = 8;
    // int val = sumOfArray(arr,n);
    // cout<<"Sum of array is  -> "<<val<<endl;

//Question find an element in array ======================
    // int arr[10] = {1,2,3,4,3,2,7,2,8,6};
    // int n = 10;
    // int target = 7;
    // int index = linearSearch(arr,n,target);
    // cout<<"index of "<<target<<" in the array is --> "<<index<<endl;


//BINARY SEARCH USING RECURSION ==================================================
    // int arr[14] = {1,2,3,4,5,6,34,45,67,98,912,4532,5782,101111};
    // int n = 14;
    // int target = 45;

    // int s = 0;
    // int e = n-1;
    // int index = binarySearch(arr,s,e,target);
    // cout<<" The element "<<target<<" is fonud in index: -> "<<index<<endl;    


// STRINGS USING RECURSION====================================================
    // string s = "";
    // reverseString(s,0,s.size()-1);
    // bool check = plaindrome(s,0,s.size()-1);
    // cout<<"main vlaue : "<<s<<" --> "<<check<<endl;

    //power of number with formula and recursion====================
    // int a = 2;
    // int b = 10;
    // int ans = powerByFormula(a,b);
    // cout<<"value of "<<a<<" to the power "<<b<<" is "<<ans<<endl;
    

//SORTING USING RECURSION ==================================================
    // int arr[8] = {2,7,1,6,9,5,3,8};
    // int arr[8] = {6 ,6 ,-6 ,-2 ,-4 ,-6 ,2 ,-6 };
    // int n = 8;
    // bubbleSort(arr,n); 
    // selectionSort(arr,n);
    // insertionSort(arr,n); // TODO--&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    // mergeSort(arr,0,n-1);
    // quickSort(arr,0,n-1);
    // print(arr,n);

//QUESTION SUBSETS(leetcode)==================================
// vector<int> nums ={1,2,3};
// vector<vector<int>> v = subsets(nums);
// for(int i = 0;i<v.size();i++){
//     for(int j =0;j<v[0].size();j++){
//         cout<<v[i][j]<<" ";
//     }cout<<endl;
// }

    return 0;
}