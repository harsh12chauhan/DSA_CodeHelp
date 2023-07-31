#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> q;

    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);

    cout<<"Size of the queue is -> "<<q.size()<<endl;
    q.pop();
    cout<<"front element of the queue is -> "<<q.front()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
return 0;
}