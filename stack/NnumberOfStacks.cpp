#include <iostream> 
#include <bits/stdc++.h> 
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int*next;

    int n,s;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];

        top = new int[n];
        for (int i = 0; i < n; i++) {
          top[i] = -1;
        }

        next = new int[s];
        for(int i = 0;i<s-1;i++){
            next[i] = i+1;
        }
        next[s-1] = -1;

        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check overflow
        if(freespot == -1){
            return false;
        }
        //find index
        int index = freespot;

        //update freespot
        freespot = next[index];

        //push element in array
        arr[index] = x;

        //update next 
        next[index] = top[m-1]; // m-1 because o based indexing

        //update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1){
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
    ~NStack(){
        delete arr;
        delete top;
        delete next;
        cout<<"memory is free !"<<endl;
    }
};
int main(){
    int N = 3; //number of stacks
    int S = 6; //size of array
    NStack obj(N,S);

    obj.push(12,1);
    cout<<"number 12 is pushed in the stack 1 "<<endl;
    obj.push(13,1);
    cout<<"number 13 is pushed in the stack 1 "<<endl;
    obj.push(14,1);
    cout<<"number 14 is pushed in the stack 1 "<<endl;
    obj.push(1,2);
    cout<<"number 1 is pushed in the stack 2 "<<endl;
    obj.push(19,3);
    cout<<"number 19 is pushed in the stack 3 "<<endl;
    obj.push(87,3);
    cout<<"number 12 is pushed in the stack 3 "<<endl;

    cout<<"poped element is  " << obj.pop(1)<<endl;;
    cout<<"poped element is  " << obj.pop(2)<<endl;;
    cout<<"poped element is  " << obj.pop(3)<<endl;;
    cout<<"poped element is  " << obj.pop(3)<<endl; 
    cout<<"poped element is  " << obj.pop(1)<<endl;;
    cout<<"poped element is  " << obj.pop(1)<<endl;;
}