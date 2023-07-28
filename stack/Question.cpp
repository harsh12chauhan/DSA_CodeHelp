#include <iostream>
#include <stack>
using namespace std;
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
int main(){
    //reverse string using stack
    string s = "harsh";
    s = reverseStringUsingStack(s);
    cout<<s<<endl;
return 0;
}