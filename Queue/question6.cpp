// interLeave the first half of the queue with second half using stack and queue 
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void qPrint(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl<<"queue is printed "<<endl;
}

// alternet from half using queue
void alterUsingQueue(queue<int> &q){
    queue<int> temp;
    int half = q.size()/2;
    for(int i = 0;i<half;i++){
        temp.push(q.front());
        q.pop();
    }
    while(!temp.empty()){
        q.push(temp.front());
        temp.pop();
        int val = q.front();
        q.pop();
        q.push(val);
    }
}

// alternet from half using stack
void alterUsingStack(queue<int> &q){
    stack<int> s;
    int half = q.size()/2;

    for(int i = 0;i<half;i++){
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for(int i = 0;i<half;i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    for(int i = 0;i<half;i++){
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        int val = q.front();
        q.pop();
        q.push(val);
    }    
}

int main(){
 queue<int> q;
    q.push(6);
    q.push(9);
    q.push(7);
    q.push(5);
    q.push(90);
    q.push(10);
    q.push(16);
    q.push(47);
    q.push(23);
    q.push(21);
    qPrint(q);

// alternet from half using queue
    // alterUsingQueue(q);
    // qPrint(q);
// alternet from half using stack
    alterUsingStack(q);
    qPrint(q);

return 0;
}