/*Recursion
TC -> O(2^n)
SC -> O(n)
*/
class Solution {
public:
    int fun(int index, int buy, vector<int>& prices)
    {
        int n = prices.size();
        if(index >= n) return 0;

        if(buy == 1)
        {
            int opt1 = fun(index + 1, buy, prices);
            int opt2 = -prices[index] + fun(index + 1, !buy, prices);
            return max(opt1, opt2);
        }
        else
        {
            int opt1 = fun(index + 1, buy, prices);
            int opt2 = +prices[index] + fun(index + 2, !buy, prices);
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
SC -> O(n * 2) + O(n)
*/
class Solution {
public:
    int fun(int index, int buy, vector<int>& prices, vector<vector<int>>& dp)
    {
        int n = prices.size();
        if(index >= n) return 0;
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
            int opt2 = +prices[index] + fun(index + 2, !buy, prices, dp);
            return dp[index][buy] = max(opt1, opt2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fun(0, 1, prices, dp);
    }
};

/*Tabulation
TC -> O(n * 2)
SC -> O(n * 2)
*/
class Solution {
public:
    int fun(int n, vector<int>& prices, vector<vector<int>>& dp)
    {
        for(int i = n-1; i >=0; i--)
        {
            dp[i][1] = max(dp[i+1][1] , -prices[i] + dp[i+1][0]);
                    int x = 0;
                    if(i+2 <= n)
                    x = dp[i+2][1];
                    dp[i][0] = max(dp[i+1][0], prices[i] + x);
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        return fun(n, prices, dp);
    }
};

/*Space Optimization
TC ->   O(n * 2)
SC -> O(2 * 2)
*/

class Solution {
public:
    int fun(int n, vector<int>& prices)
    {
        vector<int>vprev(2,0);
        vector<int>prev(2,0);

        for(int i = n-1; i >=0; i--)
        {
            vector<int>temp(2,0);
            temp[1] = max(prev[1] , -prices[i] + prev[0]);
            int x = 0;
            if(i+2 <= n)
            x = vprev[1];
            temp[0] = max(prev[0], prices[i] + x);
            vprev = prev;
            prev = temp;
        }
        return prev[1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return fun(n, prices);
    }
};
