#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// First non-repeating character in a stream
string FirstNonRepeating(string A){
	unordered_map<char,int> count;
	string ans = "";
	queue<char> q;
	for(int i =0;i<A.size();i++){
	    count[A[i]]++;
	    q.push(A[i]);
	    while(!q.empty()){
	        if(count[q.front()] >1){
	            q.pop();
	        }else{
	           ans.push_back(q.front());
	           break;
	        }
	    }
	    if(q.empty()){
	        ans.push_back('#');
	    }
	}
	return ans;
}
int main(){
string s = "aabc";
string ans = FirstNonRepeating(s);
cout<<ans<<endl;
return 0;
}