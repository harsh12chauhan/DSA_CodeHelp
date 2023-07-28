#include <iostream>
#include <stack>
using namespace std;

// reverse string using stack
string reverseStringUsingStack(string s){
    stack<char> st;
    for(int i =0;i<s.size();i++){
        st.push(s[i]);
    }

    string ans="";
    while(!st.empty()){
        ans += st.top();
        st.pop(); 
    }
    return ans;
}

// print function for stack
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<"Printing elements Done"<<endl;
}

// recursive approach to delete middle element
void deleteMiddle(stack<int>&st,int size,int count){
    //base case
    if(count == size/2){
        st.pop();
        return ;
    }

    int num = st.top();
    st.pop();
    deleteMiddle(st,size,count+1);
    st.push(num);
}

int main(){
    
//reverse string using stack
    // string s = "harsh";
    // s = reverseStringUsingStack(s);
    // cout<<s<<endl;

// delete middle element in stack
    stack<int> st;
    st.push(3);
    st.push(9);
    st.push(1);
    st.push(5);
    st.push(8);
    print(st);
    deleteMiddle(st,st.size(),0);
    print(st);

return 0;
}