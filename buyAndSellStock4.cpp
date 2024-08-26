/*
Recursion
TC -> O(2^n)
SC -> O(n)
*/
class Solution {
public:
    int fun(int index, int buy, vector<int>& prices, int k)
    {
        int n = prices.size();
        if(index == n|| k == 0) return 0;
        if(buy == 1)
        {
            int opt1 = fun(index + 1, buy, prices, k);
            int opt2 = -prices[index] + fun(index + 1, !buy, prices, k);
            return max(opt1, opt2);
        }
        else
        {
            int opt1 = fun(index + 1, buy, prices, k);
            int opt2 = prices[index] + fun(index + 1, !buy, prices, k-1);
            return max(opt1, opt2);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return fun(0, 1, prices, k);
    }
};

/*
Memoization
TC -> O(n * 2 * k)
SC -> O(n * 2 * k) + O(n)
*/
class Solution {
public:
    int fun(int index, int buy, vector<int>& prices, int k, vector<vector<vector<int>>>& dp)
    {
        int n = prices.size();
        if(index == n|| k == 0) return 0;
        if(dp[index][buy][k] != -1) return dp[index][buy][k];
        if(buy == 1)
        {
            int opt1 = fun(index + 1, buy, prices, k, dp);
            int opt2 = -prices[index] + fun(index + 1, !buy, prices, k, dp);
            return dp[index][buy][k] = max(opt1, opt2);
        }
        else
        {
            int opt1 = fun(index + 1, buy, prices, k, dp);
            int opt2 = prices[index] + fun(index + 1, !buy, prices, k-1, dp);
            return dp[index][buy][k] = max(opt1, opt2);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(0, 1, prices, k, dp);
    }
};

/*
Tabulation
TC -> O(n * 2 * k)
SC -> O(2 * k)
*/
class Solution {
public:
    int fun(int n, vector<int>& prices, int trans, vector<vector<vector<int>>>& dp)
    {
        for(int i = n-1; i >=0; i--)
        {
            for(int j = 0; j <=1; j++)
            {
                for(int k = 1; k <= trans; k++)
                {
                    if(j == 1)
                    {
                        dp[i][j][k] = max(dp[i+1][1][k], -prices[i] + dp[i+1][0][k]);
                    }
                    else
                    dp[i][j][k] = max(dp[i+1][0][k], prices[i] + dp[i+1][1][k-1]);
                }
            }
        }
        return dp[0][1][trans];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        return fun(n, prices, k, dp);
    }
};

/*
Space optimization
TC -> O(n * 2 * k)
SC -> O(2 * k)
*/
class Solution {
public:
    int fun(int n, vector<int>& prices, int trans)
    {
        vector<vector<int>>prev(2,vector<int>(trans+1,0));
        for(int i = n-1; i >=0; i--)
        {
            vector<vector<int>>temp(2,vector<int>(trans+1,0));
            for(int j = 0; j <=1; j++)
            {
                for(int k = 1; k <= trans; k++)
                {
                    if(j == 1)
                    {
                        temp[j][k] = max(prev[1][k], -prices[i] + prev[0][k]);
                    }
                    else
                    temp[j][k] = max(prev[0][k], prices[i] + prev[1][k-1]);
                }
            }
            prev = temp;
        }
        return prev[1][trans];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return fun(n, prices, k);
    }
};
