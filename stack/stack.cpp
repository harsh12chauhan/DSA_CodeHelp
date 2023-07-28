#include <iostream>
using namespace std;
class Stack{
    public:

    //data members
    int top;
    int *arr;
    int size;

    Stack(int size){
        this->size = size;
        arr =  new int[size];
        top = -1;
    }

    //functions
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }else{
            cout<<"stack is Overflow "<<endl;
        }
    }
    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout<<"Stack is underflow "<<endl;
        }
    }
    int peek(){
        if (top >= 0)
        {
            return arr[top];
        }else{
            cout<<"Stack is empty "<<endl;
            return -1;
        }
        
    }
    bool isEmpty(){
        if (top == -1)
        {
            return true;
        }else{
            return false;
        }   
    }
    ~Stack(){
        cout<<" memory is free "<<endl;
        delete arr;
    }
};
int main(){

Stack st(5);

st.push(22);
st.push(20);
st.push(12);
st.push(2);
st.push(8);
st.push(234);

cout<<" top of the stack is : -> "<<st.peek()<<endl;
st.pop();
cout<<" top of the stack is : -> "<<st.peek()<<endl;
st.pop();
cout<<" top of the stack is : -> "<<st.peek()<<endl;
st.pop();
cout<<" top of the stack is : -> "<<st.peek()<<endl;
st.pop();
cout<<" top of the stack is : -> "<<st.peek()<<endl;



return 0;
}