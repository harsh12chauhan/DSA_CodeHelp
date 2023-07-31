#include <iostream>
#include <queue>
using namespace std;
int main(){
    deque<int> d;

    d.push_back(5);
    d.push_back(3);
    d.push_front(4);
    d.push_front(2);

    cout<<"Size of the queue is -> "<<d.size()<<endl;

    cout<<"front element of the queue is -> "<<d.front()<<endl;
    cout<<"back element of the queue is -> "<<d.back()<<endl;
    d.pop_back();
    d.pop_front();
    cout<<"front element of the queue is -> "<<d.front()<<endl;
    cout<<"back element of the queue is -> "<<d.back()<<endl;
    d.pop_back();
    d.pop_front();

    if(d.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
return 0;
}