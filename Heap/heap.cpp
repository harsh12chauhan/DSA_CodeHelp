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

    void insert(int data){
        size = size + 1;
        int index = size;
        arr[index] = data;

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
    void print(){
        for(int i = 1;i<= size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
    heap h;
    h.insert(23);
    h.insert(53);
    h.insert(86);
    h.insert(9);
    h.insert(43);
    h.insert(221);
    h.insert(91);
    h.print();
return 0;
}