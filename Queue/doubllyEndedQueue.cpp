#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
class doublyEndedQueue{
    public:
    int size;
    int *arr;
    int qfront;
    int rear;
    doublyEndedQueue(int n){
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }
    bool push_front(int x){
        if(isFull()){
            return false;
        }else if(isEmpty()){
            qfront = rear = 0;
        }else if(qfront == 0 && rear != size-1){
            qfront = size-1;
        }else{
            qfront--;
        }
        arr[qfront] = x;
        return true;
    }
    bool push_back(int value){
        if(isFull()){
            return false;
        }else if(isEmpty()){
            qfront = rear = 0;
        }else if(rear == size-1){
            rear = 0;
        }else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    int pop_front(){
        if(isEmpty()){
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;
        if(qfront == rear){
            qfront = rear = -1;
        }else if(qfront == size-1){
            qfront = 0;
        }else{
            qfront++;
        }
        return ans;
    }
    int pop_rear(){
        if(isEmpty()){
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if(qfront == rear){
            qfront = rear = -1;
        }else if(rear == 0){
            rear = size-1;
        }else{
            rear--;
        }
        return ans;
    }
    int getFront(){
       if(isEmpty()){
           return -1;
       }else{
           return arr[qfront];
       }
    }
    int getRear(){
        if(isEmpty()){
           return -1;
       }else{
           return arr[rear];
       }
    }
    bool isEmpty(){
        if(qfront == -1){
            return true;
        }else{
            return false;
        }
    }
    bool isFull(){
      if ((qfront == 0 && rear == size - 1) ||
          (qfront != 0 && rear == (qfront - 1) % (size - 1))) {
            return true;
      }else{
          return false;
      }
    }
    ~doublyEndedQueue(){
        delete arr;
        cout<<"Memory is free"<<endl;
    }
};

int main(){
doublyEndedQueue obj(6);

obj.push_back(4);
obj.push_back(2);
obj.push_back(5);
obj.push_front(7);
obj.push_front(9);
obj.push_front(3);

cout<<"element "<<obj.pop_rear()<<" is pop (rear) from the queue"<<endl;
cout<<"element "<<obj.pop_rear()<<" is pop (rear) from the queue"<<endl;
cout<<"element "<<obj.pop_front()<<" is pop (front) from the queue"<<endl;

cout<<"front of the queue is -> "<<obj.getFront()<<endl;
cout<<"front of the queue is -> "<<obj.getRear()<<endl;

if(obj.isEmpty()){
    cout<<"queue is empty "<<endl;
}else{
    cout<<"queue is not empty "<<endl;
}


return 0;
}