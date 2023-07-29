#include <iostream>
#include <stack>
#include <vector>
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
// function to reverse a stack
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
//function to insert element in sorted way in stack
void insertInSortedWay(stack<int> &st,int element){
	//base case
	if(st.empty() || (!st.empty() && st.top()<element)){
		st.push(element);
		return ;
	}

	int num = st.top();
	st.pop();

	insertInSortedWay(st,element);

	st.push(num);
}
// function to sort stack using recursion
void sortStack(stack<int> &stack)
{
	//base case
	if(stack.empty()){
		return ;
	}

	int num = stack.top();
	stack.pop();

	sortStack(stack);
	
	insertInSortedWay(stack,num);
}
// check if the expression has redundant brckets
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i = 0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-'||ch =='*' ||ch =='/'){
            st.push(ch);
        }else{
            bool isRedundant = true;
            if(ch == ')'){
                while(st.top() != '('){
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if (isRedundant) {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
//function to find minimum bracketsReversal
int findMinimumCost(string str) {
  // Write your code here
  if(str.size() %2 == 1){
    return -1;
  }
  stack<char> st;
  for(int i =0;i<str.size();i++){
    char ch = str[i];
    if(ch == '{'){
        st.push(ch);
    }else{
      if(!st.empty() && st.top() == '{'){
        st.pop();
      }else{
        st.push(ch);
      }
    }
  }

  int a = 0,b = 0;
  while(!st.empty()){
    if(st.top() == '{'){
      b++;
    }else{
      a++;
    }
    st.pop();
  }

  int ans = (a+1)/2 + (b+1)/2;
  return ans;
}
//
vector<int> nextSmallElement(vector<int> arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i =n-1;i>=0;i--){
        int crr = arr[i];

        while(s.top()>=crr){
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(crr);
    }
    return ans;

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
    // int element =12;
    // stack<int> st;
    // st.push(3);
    // st.push(9);
    // st.push(1);
    // st.push(5);
    // st.push(8);
    // print(st);
    // insertAtBottom(st,element);
    // print(st);

//reverse the elements of stack 
    // reverseStack(st);
    // print(st);

// sort the stack 
    // sortStack(st);    
    // print(st);

// redundant brackets 
    // string s =  "((a+b(a/b)))";
    // if(findRedundantBrackets(s)){
    //     cout<< "There are redundent brackets in the expression "<<endl;
    // }else{
    //     cout<<"There are no redundant brackets in the expression"<<endl;
    // }

// find minimum bracketsReversal
    // string s = "}}{{{{{}}}";
    // int value = findMinimumCost(s);
    // cout<<"reversal brackets "<<value;

// next smaller element using stack
vector<int> arr = {2,1,4,3};
int n = arr.size();
vector<int> a = nextSmallElement(arr,n);
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
cout<<endl;



return 0;
}