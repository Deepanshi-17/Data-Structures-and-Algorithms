#include<vector>
using namespace std;

/*Recursion
TC -> O(2^n)
SC -> O(n)
*/
class Solution {
public:
    int fun(int index, bool buy, vector<int>& prices)
    {
        if(index == prices.size()) return 0;
        if(buy == 1)
        {
            int opt1 = fun(index + 1, buy, prices);
            int opt2 = -prices[index] + fun(index + 1, !buy, prices);
            return max(opt1, opt2);
        }
        else
        {
            int opt1 = fun(index + 1, buy, prices);
            int opt2 = +prices[index] + fun(index + 1, !buy, prices);
            return max(opt1, opt2);     
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return fun(0, 1, prices);
    }
};

/*Memoization
TC -> O(n * 2)
SC -> O(n) + O(n * 2)
*/
class Solution {
public:
    int fun(int index, bool buy, vector<int>& prices, vector<vector<int>>& dp)
    {
        if(index == prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy == 1)
        {
            int opt1 = fun(index + 1, buy, prices, dp);
            int opt2 = -prices[index] + fun(index + 1, !buy, prices, dp);
            return dp[index][buy] = max(opt1, opt2);
        }
        else
        {
            int opt1 = fun(index + 1, buy, prices, dp);
            int opt2 = +prices[index] + fun(index + 1, !buy, prices, dp);
            return dp[index][buy] = max(opt1, opt2);     
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return fun(0, 1, prices, dp);
    }
};

/*Tabulation
TC -> O(n)
SC -> O(n * 2)
*/
class Solution {
public:
    int fun(int n, vector<int>& prices, vector<vector<int>>& dp)
    {
        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int i = n-1; i >= 0; i--)
        {
            dp[i][1] = max(dp[i+1][1], -prices[i] + dp[i+1][0]);
            dp[i][0] = max(dp[i+1][0], +prices[i] + dp[i+1][1]);
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,0));
        return fun(n, prices, dp);
    }
};

/*Space Optimization
TC -> O(n)
SC -> O(2)
*/

class Solution {
public:
    int fun(int n, vector<int>& prices)
    {
        vector<int>prev(2,0);
        prev[0] = 0;
        prev[1] = 0;

        for(int i = n-1; i >= 0; i--)
        {
            vector<int>temp(2,0);
            temp[1] = max(prev[1], -prices[i] + prev[0]);
            temp[0] = max(prev[0], +prices[i] + prev[1]);
            prev = temp;
        }
        return prev[1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return fun(n, prices);
    }
};
