#include <iostream>
#include <queue>

using namespace std;
int main(){
//maxheap ===========================
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<"Size of the max heap is : "<<pq.size()<<endl;

    cout<<"Top of the max heap -> "<<pq.top()<<endl;
    pq.pop();

    cout<<"Size of the max heap is : "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"Max heap is empty!"<<endl;
    }else{
        cout<<"Max heap is empty!"<<endl;
    }
    cout<<endl;
    //minheap ===========================
    priority_queue<int,vector<int>,greater<int> >minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout<<"Size of the Min heap is : "<<minheap.size()<<endl;

    cout<<"Top of the Min heap -> "<<minheap.top()<<endl;
    minheap.pop();

    cout<<"Size of the Min heap is : "<<minheap.size()<<endl;

    if(minheap.empty()){
        cout<<"Min heap is empty!"<<endl;
    }else{
        cout<<"Min heap is empty!"<<endl;
    }

return 0;
}