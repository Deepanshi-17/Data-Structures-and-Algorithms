/*RECURSION ->
TC -> O(2^N)
SC -> O(N)*/
class Solution {
public:
    int fun(int n)
    {
        if(n <= 1) return 1;
        return fun(n-1) + fun(n-2);
    }
    int climbStairs(int n) {
        return fun(n);
    }
};

/*Memoization->
TC -> O(N)
SC -> O(N) -> recursion stack space + O(N) -> dp array*/
class Solution {
public:
    int fun(int n, vector<int>&dp)
    {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fun(n-1, dp) + fun(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1)
        return fun(n, dp);
    }
};

/*Tabulation->
TC -> O(N)
SC -> O(N) -> DP Array*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

/*Space Optimization->
TC -> O(N)
SC -> O(2)*/

class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev = 1;
        for(int i = 2; i <=n; i++)
        {
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};