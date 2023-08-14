#include <iostream>
#include <vector>
using namespace std;
// recursive + memoization top-down approach dp ----------------------------
int solveMem(int x, vector<int> &num, vector<int> &dp)
{
    // base case
    if (x == 0)
    {
        return 0;
    }
    if (x < 0)
    {
        return INT16_MAX;
    }
    if (dp[x] != -1)
    {
        return dp[x];
    }
    int mini = INT16_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveMem(x - num[i], num, dp);
        if (ans != INT16_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    dp[x] = mini;

    return mini;
}

//tabular bottom-up approach dp ----------------------------------------
int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT16_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT16_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }
    if (dp[x] == INT16_MAX)
    {
        return -1;
    }
    return dp[x];
}
//minimun elements require to get  x ---------------------------------------------
int minimumElements(vector<int> &num, int x)
{
    //solution 1: recursion and memoization
    vector<int> dp(x+1,-1);
    int ans = solveMem(x, num, dp);
    if(ans == INT16_MAX){
        return -1;
    }
    return ans;

    //soluation 2: tabular
    // return solveTab(num, x);
}
int main()
{   vector<int> num={1,2,3};
    int x = 7;
    int ans = minimumElements(num,x);
    cout<<ans<<endl;
    return 0;
}