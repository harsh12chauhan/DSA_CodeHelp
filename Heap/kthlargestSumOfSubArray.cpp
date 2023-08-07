#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//function for K-th Largest Sum Subarray -------------------------------------------
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int> >mini;
	
	int n = arr.size();
	for(int i = 0;i<n;i++){
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if(mini.size() < k){
				mini.push(sum);
			}else{
				if(sum > mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}
    }
	return mini.top();
}

int main(){

// K-th Largest Sum Subarray ======================================
    // vector<int> arr = {0,-2,-5,2,0};
    // int k = 9;
    vector<int> arr = {5,4,-8,6};
    int k = 10;

    int ans = getKthLargest(arr,k);

    cout<<" K-th Largest Sum Subarray is -> "<<ans<<endl;

return 0;
}