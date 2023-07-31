//Design a stack that supports 
// getMin() in O(1) time and O(1)space

#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<int>s;
    int mini;
    
    public:
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini = data;
        }else{
            if(data < mini){
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            } else {
              s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }

        int curr = s.top();
            s.pop();
        if (curr > mini) {
          return curr;
        }else{
            int prevMini = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMini;
        }
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr < mini){
            return mini;
        }else{
            return curr;
        }
    }

    int getMin() {
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};
int main(){
SpecialStack obj;
cout<<"Pushing element in the stack "<<endl;
obj.push(13);
cout<<"Pushing element in the stack "<<endl;
obj.push(47);
cout<<"Top of the stack is -> " <<obj.top()<<endl;;
cout<<"Pushing element in the stack "<<endl;
obj.push(8);
cout<<"Poping the element "<<obj.pop()<<" from stack "<<endl;
cout<<"Minimum element in stack is -> "<<obj.getMin()<<endl;;


return 0;
}