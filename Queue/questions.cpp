#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//function to reverse queue using stack
queue<int> rev(queue<int> q)
{
    stack<int> s;
    
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    return q;
}

//function to reverse queue using recursion
void recursionRev(queue<int>&q){
    //base case
    if(q.empty()){
        return;
    }

    int val = q.front();
    q.pop();
    recursionRev(q);
    q.push(val);
}

//function to print queue 
void qPrint(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl<<"queue is printed "<<endl;
}
int main(){
    queue<int> q;
    q.push(6);
    q.push(9);
    q.push(7);
    q.push(5);
    q.push(1);
    qPrint(q);
//reverse queue using stack
    // q = rev(q);    
    // qPrint(q);

//reverse queue using recursion
    recursionRev(q);  
    qPrint(q);



return 0;
}