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

// function to check weather the string has valid prantheses
bool validPrantheses(string s){
    stack<char> st;
    char c1 = '}',c2 =')',c3=']';
    for(int i = 0;i<s.size();i++){
        char ch = s[i];

        //if opening bracket push in stack
        if (ch == '{' || ch == '[' || ch == '(') {
          st.push(ch);

        // if closing bracket then check top and pop
        } else{
            if(!st.empty()){
                char t = st.top();
                if (t == '{' && ch == '}'){
                    st.pop();
                }else if (t == '(' && ch == ')'){
                    st.pop();
                }else if (t == '[' && ch == ']'){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

//functino to insert the element in the bottom of the stack using recursion
void insertAtBottom(stack<int>&st,int element){
    //base case
    if(st.empty()){
        st.push(element);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtBottom(st,element);

    st.push(num);
}
//
void reverseStack(stack<int>&st){
    //base case
    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st,num);

}
int main(){
    
//reverse string using stack
    // string s = "harsh";
    // s = reverseStringUsingStack(s);
    // cout<<s<<endl;

// delete middle element in stack
    // stack<int> st;
    // st.push(3);
    // st.push(9);
    // st.push(1);
    // st.push(5);
    // st.push(8);
    // print(st);
    // deleteMiddle(st,st.size(),0);
    // print(st);

//valid prantheses
    //  string s = "{{([({)])}}";
    //  if(validPrantheses(s)){
    //     cout<<"Balanced Prantheses "<<endl;
    //  }else{
    //     cout<<"Not a Balanced Prantheses "<<endl;
    //  }

//insert an element in the bottom of the stack
    int element =12;
    stack<int> st;
    st.push(3);
    st.push(9);
    st.push(1);
    st.push(5);
    st.push(8);
    print(st);
    insertAtBottom(st,element);
    print(st);

//reverse the elements of stack 
    reverseStack(st);
    print(st);

return 0;
}