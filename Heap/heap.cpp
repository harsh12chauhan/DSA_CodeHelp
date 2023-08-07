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

    //insertion in heap ----------------------------------
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
    
    // deletion in heap ----------------------------------
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
int main(){
    heap h;

//insertion in heap =========================================
    h.insert(23);
    h.insert(53);
    h.insert(86);
    h.insert(9);
    h.insert(43);
    h.insert(221);
    h.insert(91);
    h.print();

//deletion in heap ===========================================
    h.deletion();
    h.print();

return 0;
}