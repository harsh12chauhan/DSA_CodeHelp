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

//function First negative integer in every window of size k
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
    deque<long long int> dq;
    vector<long long> ans;
    for(int i = 0;i<K;i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    //storing answer
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }else{
        ans.push_back(0);
    }
    //process for remaining window
    for(int i = K;i<N;i++){
        //removal
        if(!dq.empty() && i-dq.front() >= K){
            dq.pop_front();
        }
        //addition
        if(A[i] < 0){
            dq.push_back(i);
        }
        //storing answer
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }
    return ans;
}
//function for reverse first k elements from queue
queue<int> reverseKElements(queue<int> q, int k) {
    stack<int> s;
    for(int i = 0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    int remainingElements = q.size() - k;
    for(int i =0;i<remainingElements;i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
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
    // recursionRev(q);  
    // qPrint(q);

// First negative integer in every window of size k
    // long long int N = 5;
    // long long int A[] = {-8, 2, 3, -6, 10};
    // long long int K = 2;
    // vector<long long> v = printFirstNegativeInteger(A,N,K);
    // cout<<"negative integers are -> "<<endl;
    // for(int i =0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }cout<<endl;

//reverse first k elements from queue
    int k = 3;
    q = reverseKElements(q,k);
    qPrint(q);

return 0;
}