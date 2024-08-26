/*
Recursion
TC -> O(2 ^ n)
SC -> O(n)
*/
class Solution {
public:
    int fun(int index, vector<int>& prices, int buy, int fee)
    {
        int n = prices.size();
        if(index == n) return 0;
        if(buy == 1)
        {
            return max(fun(index + 1, prices, buy, fee), -prices[index] + fun(index + 1, prices, !buy, fee));
        }
        else
        {
            return max(fun(index + 1, prices, buy, fee), +prices[index] - fee + fun(index + 1, prices, !buy, fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return fun(0, prices, 1, fee);
    }
};

/*
Memoization
TC -> O(n * 2)
SC -> O(n * 2) + O(n)
*/
class Solution {
public:
    int fun(int index, vector<int>& prices, int buy, int fee, vector<vector<int>>& dp)
    {
        int n = prices.size();
        if(index == n) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy == 1)
        {
            return dp[index][buy] = max(fun(index + 1, prices, buy, fee, dp), -prices[index] + fun(index + 1, prices, !buy, fee, dp));
        }
        else
        {
            return dp[index][buy] = max(fun(index + 1, prices, buy, fee, dp), +prices[index] - fee + fun(index + 1, prices, !buy, fee, dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fun(0, prices, 1, fee, dp);
    }
};

/*
Tabulation
TC -> O(n * 2)
SC -> O(n * 2)
*/
class Solution {
public:
    int fun(int n, vector<int>& prices, int fee, vector<vector<int>>& dp)
    {
        for(int i = n-1; i >=0; i--)
        {
            dp[i][1] = max(dp[i+1][1] , -prices[i] + dp[i+1][0]);
            dp[i][0] = max(dp[i+1][0] , prices[i] - fee + dp[i+1][1]);
        }
      return dp[0][1];   
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        return fun(n, prices, fee, dp);
    }
};

/*
Space Optimization
TC -> O(n * 2)
SC -> O(2 * 2)
*/

class Solution {
public:
    int fun(int n, vector<int>& prices, int fee)
    {
        vector<int>prev(2,0);
        for(int i = n-1; i >=0; i--)
        {
            vector<int>temp(2,0);
            temp[1] = max(prev[1] , -prices[i] + prev[0]);
            temp[0] = max(prev[0] , prices[i] - fee + prev[1]);
            prev = temp;
        }
      return prev[1];   
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return fun(n, prices, fee);
    }
};
