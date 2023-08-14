#include<bits/stdc++.h>
using namespace std;
// function of fibonacci ----------------------------------------------------
int fibo(int n,int *dp){
        if(n == 1 || n == 0){
                return n;
        }
        // step 3
        if(dp[n] != -1){
                return dp[n];
        }
        // step 2
        dp[n]  = fibo(n-1,dp) + fibo(n-2,dp);
        return dp[n];
}
//fibonacci series using DP ==================================================
int main()
{
       int n = 13;

        // step 1
       int*dp = new int[n+1];
        //OR -> vector<int> dp(n+1);

       for(int i=0;i<=n+1;i++){
               dp[i] = -1;
       }

       cout<< fibo(n,dp)<<endl;
       
       delete dp;

       return 0;
}