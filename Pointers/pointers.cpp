#include <iostream>
using namespace std;

void print(int *p){
    *p = *p+1;
    cout<<"inside function : "<<p<<endl;
}

void printarray(int arr[],int size){
    cout<<"inside the function before "<<*(arr+1)<<endl;
    *(arr+1) = 4;
    cout<<"inside the function after "<<*(arr+1)<<endl;
}

int main(){
    // char ch[6] = "harsh"; 
    // char *c = &ch[0];
    // cout<<ch<<endl;
    // cout<<&c<<endl;

// passing pointers in function================

    // int a = 5;
    // int *p = &a;
    // cout<<"before : "<<*p<<endl;
    // print(p);
    // cout<<"after : "<<*p<<endl;

// passing array in function =================

    // int arr[5] = {1,2,3,4,5};
    // cout<<"before : "<<arr<<endl;
    // printarray(arr,5);
    // cout<<"after : "<<arr[1]<<endl;


// ================================================================

    int i = 5;
    int *p = &i;
    int **p2= &p;

    cout<<"printing i: "<<i<<endl;
    cout<<"printing i using *p : "<<*p<<endl;
    cout<<"printing i using **p2 : "<<**p2<<endl;
    cout<<endl;
    cout<<"address of i : "<<&i<<endl;
    cout<<"address of i using p: "<<p<<endl;
    cout<<"address of i using p2: "<<*p2<<endl;
    cout<<endl;

    cout<<"address of p : "<<&p<<endl;
    cout<<"address of p2 : "<<&p2<<endl;


    return 0;
}