#include <iostream>
#include <vector>
using namespace std;

// recursive solution  but gets  -> TLE-------------------------------------------------------
// int solveTLE(int n,vector<int> cost){
//     //base case
//     if(n == 0){
//         return cost[0];
//     }
//     if(n == 1){
//         return cost[1];
//     }
//  int ans =  cost[n] + min(solveTLE(n-1,cost),solveTLE(n-2,cost));
//     return ans;
// }

// recursive solution with memoization top-down DP approach ------------------------------------
int solve2(int n,vector<int> cost,vector<int>& dp){
    //base case
    if(n == 0){
        return cost[0];
    }
    if(n == 1){
        return cost[1];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = cost[n] + min(solve2(n-1,cost,dp),solve2(n-2,cost,dp));
    return dp[n];
}
// tabular solution bottom-up DP approach ------------------------------------
// int solve3(int n,vector<int> cost){
//     vector<int> dp(n+1);
//         dp[0] = cost[0];
//         dp[1] = cost[1];
//         for(int i=2;i<n;i++){
//             dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
//         }
    
//     return min(dp[n-1],dp[n-2]);
// }

// normal soluation or SPACE OPTIMIZATION APPROACH DP--------------------------
// int solve4(int n,vector<int> cost){
//         int prev1 = cost[1];
//         int prev2 = cost[0];
//         for(int i=2;i<n;i++){
//             int curr = cost[i] + min(prev1,prev2);
//             prev2 = prev1;
//             prev1 = curr;
//         }
    
//     return min(prev1,prev2);
// }
//DP solutions with different approaches -------------------------------------
int minCostClimbingStairs(vector<int>& cost) {
    
    int n = cost.size();
    //soluation 1:
    // int ans = min(solveTLE(n-1,cost),solveTLE(n-2,cost));
    // return ans;

    //soluation 2:
    vector<int> dp(n+1,-1);
    int ans = min(solve2(n-1,cost,dp),solve2(n-2,cost,dp));
    return ans;

    //soluation 3:
    // return solve3(n,cost);

    //soluation 4:
    // return solve4(n,cost);
}
//min cost climbing stairs problem with DP ============================
int main(){
vector<int> cost ={10,15,20};
int ans = minCostClimbingStairs(cost);
cout<<ans<<endl;
return 0;
}