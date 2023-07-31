#include <iostream>
using namespace std;
class Queue {
    int size;
    int *arr;
    int qfront;
    int rear;
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    /*----------------- Public Functions of Queue -----------------*/
    bool isEmpty() {
        if(qfront == rear){
            return true;
        }else{
            return false;
        }
    }
    void enqueue(int data) {
        if(rear == size){
            return;
        }
        arr[rear] =data;
        rear++;
    }
    int dequeue() {
        if(qfront == rear){
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        return ans;
    }
    int front() {
        if(qfront == rear){
            return -1;
        }
        return arr[qfront];
    }
    ~Queue(){
        delete arr;
        cout<<"Memory is free"<<endl;
    }
};
int main(){
    Queue obj;

    obj.enqueue(4);
    obj.enqueue(2);
    obj.enqueue(5);
    obj.enqueue(7);

    cout<<"front of the queue is -> "<<obj.front()<<endl;
    cout<<"element "<<obj.dequeue()<<" is dequeue(pop) from the queue"<<endl;
    cout<<"front of the queue is -> "<<obj.front()<<endl;
    if(obj.isEmpty()){
        cout<<"Queue is empty "<<endl;
    }else{
        cout<<"Queue is not empty "<<endl;
    }

return 0;
}