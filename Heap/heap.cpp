#include <iostream>
using namespace std;

class heap{
    public:
    int *arr;
    int size;

    heap(){
        arr = new int[100];
        arr[0] = -1;
        size = 0;
    }
    ~heap(){
        delete arr;
        cout<< "memory is free";
    }
    // print the array -----------------------------
    void print(){
        for(int i = 1;i<= size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //insertion in max heap ----------------------------------
    void insert(int data){
        //step1: increment the size
        size = size + 1;
        int index = size;

        //step2: insert the element in last
        arr[index] = data;

        //step3: take the last element to its correct position
        while(index > 1){

            int parent = index/2;
            if(arr[parent] < arr[index]){

                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                return ;
            }
        }
    }
    
    // deletion in max heap ----------------------------------
    void deletion(){
        //step1:put last element into first element
        arr[1] = arr[size];

        //step2: remove last element
        size--;

        //step3: take the first/root element to its correct position
        int index = 1;
        while(index<size){
            int leftIndex = 2*index;
            int rightIndex = 2*index+1;

            if(leftIndex <size && arr[index] < arr[leftIndex]){
                swap(arr[index],arr[leftIndex]);
                index = leftIndex;
            }
            else if(rightIndex < size && arr[index] < arr[rightIndex]){
                swap(arr[index],arr[rightIndex]);
                index = rightIndex;
            }else{
                return;
            }
        }
    }
};

//heapify function -------------------------------------------
void heapify(int arr[],int n, int i){
    int largest = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;

    if(leftIndex <= n && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }
    if(rightIndex <= n && arr[largest] < arr[rightIndex]){
        largest =  rightIndex;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

//heap sort ---------------------------------------------------------------------------
void heapSort(int arr[],int n){
    int size = n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

int main(){

// 1-BASED INDEXING ------------------------------------------------------------------------
    heap h;
//insertion in max heap =========================================
    // h.insert(23);
    // h.insert(53);
    // h.insert(86);
    // h.insert(9);
    // h.insert(43);
    // h.insert(221);
    // h.insert(91);
    // h.print();

//deletion in max heap ===========================================
    // h.deletion();
    // h.print();

// heapify ======================================================
    int arr1[6] = {-1,54,53,52,55,56};
    int n = 5;

    //printing the array=====
    for (int i = 1; i <=n; i++){
        cout<<arr1[i]<<" ";
    }cout<<endl;

    //converting in to heap=====
    for (int i =n/2 ; i >0; i--)
    {
        heapify(arr1,n,i);
    }

    // in above we are converting our array into heap
//heap sort =======================================================

    heapSort(arr1,n);

    //printing the array=====
    for (int i = 1; i <=n; i++){
        cout<<arr1[i]<<" ";
    }cout<<endl;

return 0;
}