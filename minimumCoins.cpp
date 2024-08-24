/*
Recursion
TC -> O(2 ^ n * amount)
SC -> O(n)
*/

class Solution {
public:
    int fun(int index, vector<int>& arr, int sum)
    {
        if(sum == 0) return 0;
        if(index == 0)
        {
            if(sum % arr[0] == 0) return sum / arr[0];
            return 1e9;
        }
        int take = 1e9;
        if(arr[index] <= sum)
        take = 1 + fun(index, arr, sum - arr[index]);
        int not_take = fun(index -1, arr, sum);

        return min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int x = fun(n-1, coins, amount);
        return x == 1e9? -1: x;
    }
};

/*
Memoization
TC -> O(N * T)
SC -> O(N * T) + O(N)
*/
class Solution {
public:
    int fun(int index, vector<int>& arr, int sum, vector<vector<int>>& dp)
    {
        if(sum == 0) return 0;
        if(index == 0)
        {
            if(sum % arr[0] == 0) return sum / arr[0];
            return 1e9;
        }
        if(dp[index][sum] != -1) return dp[index][sum];
        int take = 1e9;
        if(arr[index] <= sum)
        take = 1 + fun(index, arr, sum - arr[index], dp);
        int not_take = fun(index -1, arr, sum, dp);

        return dp[index][sum] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1, -1));
        int x = fun(n-1, coins, amount, dp);
        return x == 1e9? -1: x;
    }
};

/*
Tabulation
TC -> O(N * T)
SC -> O(N * T)
*/

class Solution {
public:
    int fun(int n, vector<int>& arr, int sum, vector<vector<int>>& dp)
    {
        for(int i = 0; i < n; i++)
        dp[i][0] = 0;

        for(int i = 0; i <= sum; i++)
        {
            if(i % arr[0] == 0) 
            dp[0][i] = i/arr[0];
            else dp[0][i] = 1e9;
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                int take = 1e9;
                if(arr[i] <= j)
                take = 1 + dp[i][j-arr[i]];
                int notTake = dp[i-1][j];
                dp[i][j] = min(take, notTake);
            }
        }
        return dp[n-1][sum];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1, 1e9));
        int x = fun(n, coins, amount, dp);
        return x == 1e9? -1: x;
    }
};

/*
Space Optimization
TC -> O(N * T)
SC -> O(2 * T)
*/

class Solution {
public:
    int fun(int n, vector<int>& arr, int sum)
    {
        vector<int>prev(sum + 1, 1e9);
         prev[0] = 0;      
        for(int i = 0; i <= sum; i++)
        {
            if(i % arr[0] == 0) 
            prev[i] = i/arr[0];
        }

        for(int i = 1; i < n; i++)
        {
            vector<int>temp(sum + 1, 1e9);
            temp[0] = 0;
            for(int j = 1; j <= sum; j++)
            {
                int take = 1e9;
                if(arr[i] <= j)
                take = 1 + temp[j-arr[i]];
                int notTake = prev[j];
                temp[j] = min(take, notTake);
            }
            prev = temp;
        }
        return prev[sum];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int x = fun(n, coins, amount);
        return x == 1e9? -1: x;
    }
};