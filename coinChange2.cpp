/*Recursion
TC -> O(2 ^ n)
SC -> O(n)*/
class Solution {
public:
    int fun(int index, vector<int>& coins, int amount, int n)
    {
        if(amount == 0) return 1;
        if(index == 0)
        {
            if(amount % coins[index] == 0) return 1;
            return 0;
        }
        int take = 0;
        if(coins[index] <= amount)
        take = fun(index, coins, amount - coins[index], n);
        int not_take = fun(index - 1, coins, amount, n);

        return take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return fun(n-1, coins, amount, n);
    }
};

/*Memoization
TC -> O(n * amount)
SC -> O(n * amount) + O(n)*/
class Solution {
public:
    int fun(int index, vector<int>& coins, int amount, int n, vector<vector<int>>& dp)
    {
        if(amount == 0) return dp[index][amount] = 1;
        if(index == 0)
        {
            if(amount % coins[index] == 0) return 1;
            return dp[index][amount] = 0;
        }

        if(dp[index][amount] != -1) return dp[index][amount];
        int take = 0;
        if(coins[index] <= amount)
        take = fun(index, coins, amount - coins[index], n, dp);
        int not_take = fun(index - 1, coins, amount, n, dp);

        return dp[index][amount] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1, -1));
        return fun(n-1, coins, amount, n, dp);
    }
};

/*Tabulation
TC -> O(n * amount)
SC -> O(n * amount)
*/
class Solution {
public:
    int fun(int index, vector<int>& coins, int amount, int n, vector<vector<int>>& dp)
    {
        for(int i = 0; i < n; i++)
        dp[i][0] = 1;
        for(int i = 0; i <= amount; i++)
        {
            if(i % coins[0] == 0) dp[0][i] = 1;
            else dp[0][i] = 0;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                int take = 0;
                if(coins[i] <= j)
                take = dp[i][j-coins[i]];
                int not_take = dp[i-1][j];

                dp[i][j] = take + not_take;
            }
        }
        return dp[n-1][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1, 0));
        return fun(n-1, coins, amount, n, dp);
    }
};

/*Space optimization
TC -> O(n * amount)
SC -> O(2 * amount)
*/
class Solution {
public:
    int fun(int index, vector<int>& coins, int amount, int n)
    {
        vector<int>prev(amount + 1, 0);
        for(int i = 0; i < n; i++)
        prev[0] = 1;
        for(int i = 0; i <= amount; i++)
        {
            if(i % coins[0] == 0) prev[i] = 1;
            else prev[i] = 0;
        }
        for(int i = 1; i < n; i++)
        {
            vector<int>temp(amount + 1);
            temp[0] = 1;
            for(int j = 1; j <= amount; j++)
            {
                int take = 0;
                if(coins[i] <= j)
                take = temp[j-coins[i]];
                int not_take = prev[j];

                temp[j] = take + not_take;
            }
            prev = temp;
        }
        return prev[amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return fun(n-1, coins, amount, n);
    }
};