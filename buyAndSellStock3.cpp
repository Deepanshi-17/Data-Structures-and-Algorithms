/*Recursion
TC -> O(2 ^ n)
SC -> O(n)
*/
class Solution {
public:
    int fun(int index, vector<int>& prices, int buy, int transaction)
    {
        int n = prices.size();
        if(index == n || transaction == 0) return 0;
        if(buy == 1)
        {
            int opt1 = fun(index + 1, prices, buy, transaction);
            int opt2 = -prices[index] + fun(index + 1, prices, !buy, transaction);
            return max(opt1, opt2);
        }
        else      
        {
            int opt1 = fun(index + 1, prices, buy, transaction);
            int opt2 = prices[index] + fun(index + 1, prices, !buy, transaction - 1);
            return max(opt1, opt2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return fun(0, prices, 1, 2);
    }
};

/*Memoization
TC -> O(n * 2 * 3)
SC -> O(n * 2 * 3) + O(n)
*/
class Solution {
public:
    int fun(int index, vector<int>& prices, int buy, int transaction, vector<vector<vector<int>>>& dp)
    {
        int n = prices.size();
        if(index == n || transaction == 0) return 0;
        if(dp[index][buy][transaction] != -1) return dp[index][buy][transaction];
        if(buy == 1)
        {
            int opt1 = fun(index + 1, prices, buy, transaction, dp);
            int opt2 = -prices[index] + fun(index + 1, prices, !buy, transaction, dp);
            return dp[index][buy][transaction] = max(opt1, opt2);
        }
        else      
        {
            int opt1 = fun(index + 1, prices, buy, transaction, dp);
            int opt2 = prices[index] + fun(index + 1, prices, !buy, transaction - 1, dp);
            return dp[index][buy][transaction] = max(opt1, opt2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return fun(0, prices, 1, 2, dp);
    }
};

/*Tabulation
TC -> O(n * 2 * 3)
SC -> O(n * 2 * 3)
*/
class Solution {
public:
    int fun(int n, vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j <=1; j++)
            {
                for(int k = 1; k <=2; k++)
                {
                    if(j == 1)
                    dp[i][j][k] = max(dp[i+1][1][k], -prices[i] + dp[i+1][0][k]);
                    else
                    dp[i][j][k] = max(dp[i+1][0][k], prices[i] + dp[i+1][1][k-1]);
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        return fun(n, prices, dp);
    }
};

/*Space Optimization
TC -> O(n * 2 * 3)
SC -> O(2*3)
*/
class Solution {
public:
    int fun(int n, vector<int>& prices)
    {
        vector<vector<int>>prev(2,vector<int>(3,0));
        for(int i = n-1; i >= 0; i--)
        {
            vector<vector<int>>temp(2,vector<int>(3,0));
            for(int j = 0; j <=1; j++)
            {
                for(int k = 1; k <=2; k++)
                {
                    if(j == 1)
                    temp[j][k] = max(prev[1][k], -prices[i] + prev[0][k]);
                    else
                    temp[j][k] = max(prev[0][k], prices[i] + prev[1][k-1]);
                }
            }
            prev = temp;
        }
        return prev[1][2];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return fun(n, prices);
    }
};
