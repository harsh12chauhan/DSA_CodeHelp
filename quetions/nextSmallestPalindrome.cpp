#include <iostream>
#include <vector>
using namespace std;
// function for next smallest palindrome GFG
vector<int> generateNextPalindrome(int num[], int n) {
     bool change = 1;
     for(int i =0;i<n/2;i++){
         if(num[i] < num[n-i-1]){
             change = 1;
         }else if(num[i] > num[n-i-1]){
             change = 0;
         }
         num[n-i-1] = num[i];
     }
     
     vector<int> ans(n);
     for(int i=0;i<n;i++){
         ans[i]=num[i];
     }
     
     int midIndex = n/2;
     
     bool carry = change;
     while(carry && midIndex <n){
         if(ans[midIndex] == 9){
             ans[midIndex] = 0;
             ans[n-midIndex-1] = 0;
         }else{
             ++ans[midIndex];
             ans[n-midIndex-1] = ans[midIndex];
             carry = 0;
         }
         ++midIndex;
     }
     if(carry){
         ans[0] = 1;
         ans.push_back(1);
     }
     
    return ans;
     
    
}
// next smallest palindrome GFG ====================================================
int main(){
    int num[]={9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};
    int n = 11;

    vector<int> ans = generateNextPalindrome(num,n);
    //output  -> 9 4 1 8 8 0 8 8 1 4 9 

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
return 0;
}
