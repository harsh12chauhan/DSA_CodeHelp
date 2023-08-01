#include <iostream>
using namespace std;
class kQueue{
    int size;
    int *arr;
    int *front;
    int *rear;
    int*next;
    int freeSpot;
    public:
        kQueue(int n,int k){
            this->size = n;
            this->arr = new int[size];
            this->front = new int[k];
            this->rear = new int[k];
            for(int i = 0;i<k;i++){
                front[i] = -1;
                rear[i] = -1;
            }
            next = new int[n];
            for(int i = 0;i<n;i++){
                next[i] = i+1;
            }
            next[size-1] = -1;

            freeSpot = 0;

        }
        void enqueue(int data,int qn){
            //  overflow condition
            if(freeSpot == -1){
                cout<<"Queue is overflowed "<<endl;
                return ;
            }

            //find index
            int index  = freeSpot;

            //update freespot
            freeSpot = next[index];

            //if we are inserting first element
            if(front[qn-1] == -1){  // qn-1 becaue o based indexing
                    front[qn-1] = index;
            }else{
                next[rear[qn-1]] = index;
            }

            next[index] =  -1;

            // move rear to free space
            rear[qn-1] = index;

            // push element ;
            arr[index] =  data;
        }
        int deque(int qn){
            //check underflow 
            if(front[qn-1] == -1){
                cout<<" Queue is empty "<<endl;
                return -1;
            }
            
            // find index
            int index = front[qn-1];

            // front ko aage badhayo
            front[qn-1] = next[index];

//updation the next list as new free space is found
            //freespots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;

            //return poped element
            return arr[index];

        }

        ~kQueue(){
            delete arr,front,rear,next;
            cout<<"Memory is free "<<endl;
        }
};
int main(){
    kQueue q(10,3);

    q.enqueue(12,1);  // 12 3 92 
    q.enqueue(1,3);   // 162 23 10
    q.enqueue(162,2);  // 1 18
    q.enqueue(3,1);
    q.enqueue(92,1);
    q.enqueue(23,2);
    q.enqueue(18,3);
    q.enqueue(10,2);
    q.enqueue(10,2);
    q.enqueue(92,1); 

    q.enqueue(92,1); // for checking overflow

    cout<<"poped element is ->"<<q.deque(1)<<endl;
    cout<<"poped element is ->"<<q.deque(3)<<endl;
    cout<<"poped element is ->"<<q.deque(2)<<endl;
    cout<<"poped element is ->"<<q.deque(1)<<endl;
    cout<<"poped element is ->"<<q.deque(1)<<endl;
    cout<<"poped element is ->"<<q.deque(2)<<endl;
    cout<<"poped element is ->"<<q.deque(3)<<endl;
    cout<<"poped element is ->"<<q.deque(2)<<endl;
    cout<<"poped element is ->"<<q.deque(2)<<endl;
    cout<<"poped element is ->"<<q.deque(2)<<endl;

    // for checking underflow
    cout<<"poped element is ->"<<q.deque(1)<<endl;


return 0;
}