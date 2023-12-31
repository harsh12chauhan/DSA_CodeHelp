#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
class CircularQueue{
    public:
    int size;
    int *arr;
    int qfront;
    int rear;
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }
    bool enqueue(int value){
        //check if queue is full ?
        if((qfront == 0 && rear == size-1)||(rear == (qfront-1)%(size-1))){
            return false;
        }else if(qfront == -1) // for first element
        { 
            qfront = rear = 0;
        }else if(rear == size-1) // to maintain cyclic nature
        { 
            rear = 0;
        }else{          //normal push
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    int dequeue(){
        if(qfront == -1){ // check if queue is empty ?
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;
        if(qfront == rear) //if only single element is present in queue
        {
            qfront = rear = -1;
        }else if(qfront == size-1)  // to maintain cyclic nature
        { 
            qfront = 0;
        }else{       //normal pop
            qfront++;
        }
        return ans;
    }
    ~CircularQueue(){
        delete arr;
        cout<<"Memory is free"<<endl;
    }
};

int main(){
CircularQueue obj(6);

obj.enqueue(4);
obj.enqueue(2);
obj.enqueue(5);
obj.enqueue(7);
obj.enqueue(9);
obj.enqueue(3);

cout<<"element "<<obj.dequeue()<<" is dequeue(pop) from the queue"<<endl;
cout<<"element "<<obj.dequeue()<<" is dequeue(pop) from the queue"<<endl;
cout<<"element "<<obj.dequeue()<<" is dequeue(pop) from the queue"<<endl;
cout<<"element "<<obj.dequeue()<<" is dequeue(pop) from the queue"<<endl;
cout<<"element "<<obj.dequeue()<<" is dequeue(pop) from the queue"<<endl;
cout<<"element "<<obj.dequeue()<<" is dequeue(pop) from the queue"<<endl;

return 0;
}