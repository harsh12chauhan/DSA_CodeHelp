#include <iostream>
#include<vector>
using namespace std;

// recursive brut force approach TLE for large numbers
// #define MOD 10000000007
// int findCatalan(int n) 
// {
//     if(n <= 1){
//         return  1;
//     }
//     int res = 0;
//     for(int i=0;i<=n-1;i++){
//         cout<<"i - >"<<i<<" n-i-1 ->"<<n-i-1<<" res -> "<<res<<endl;
//         res += findCatalan(i)%MOD * findCatalan(n-i-1)%MOD;
//     }
//     return res%MOD;
// }

// DP solution bottom-up approach 
int findCatalan(int n) {
    const int mod = 1e9+7;
    vector<long long> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<n+1;i++){
        for(int j = 0;j<i;j++){
            dp[i] = (dp[i] + (dp[j] * dp[i-j-1])%mod)%mod;
        }
    }
    return dp[n];
}
// Catalan Number ===============================================================
int main(){
int n = 5;
cout<< findCatalan(n)<<endl;;
return 0;
}