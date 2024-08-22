/*RECURSION ->
TC -> O(2^N)
SC -> O(N)*/


class Solution{   
public:
    bool fun(int index, int n, vector<int>& arr, int sum)
    {
        if(sum == 0) return true;
        if(index == 0)
        {
            if(sum == arr[index])
            return true;
            return false;
        }
        bool pick = false;
        if(arr[index] <= sum)
        {
            pick = fun(index - 1, n, arr, sum - arr[index]);
        }
        bool not_pick = fun(index - 1, n, arr, sum);
        return pick | not_pick;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return fun(n-1, n, arr, sum);
    }
};

/*Memoization ->
TC -> O(N)
SC -> O(N) -> recursion stack space + O(N * sum) -> DP array*/


class Solution{   
public:
    bool fun(int index, int n, vector<int>& arr, int sum, vector<vector<int>>& dp)
    {
        if(sum == 0) return true;
        if(index == 0)
        {
            if(sum == arr[index])
            return true;
            return false;
        }
        if(dp[index][sum] != -1) return dp[index][sum];
        bool pick = false;
        if(arr[index] <= sum)
        {
            pick = fun(index - 1, n, arr, sum - arr[index], dp);
        }
        bool not_pick = fun(index - 1, n, arr, sum, dp);
        return dp[index][sum] = pick | not_pick;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
        return fun(n-1, n, arr, sum, dp);
    }
};

/*Tabulation ->
TC -> O(N *sum)
SC -> O(N * sum) */

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>>dp(n, vector<bool>(sum + 1, false));
        if(arr[0] <= sum)
        {
            dp[0][arr[0]] = true;
        }
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool take = false;
                if(arr[i] <= j)
                take = dp[i-1][j-arr[i]];
                bool not_take = dp[i-1][j];
                dp[i][j] = take | not_take;
            }
        }
        
        return dp[n-1][sum];
    }
};

/*Space Optimization
TC -> O(N * sum)
SC -> O(2 * sum)*/

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<bool>prev(sum + 1, false);
        vector<bool>temp(sum + 1, false);
        if(arr[0] <= sum)
        {
            prev[arr[0]] = true;
        }
        prev[0] = true;
        temp[0] = true;
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool take = false;
                if(arr[i] <= j)
                take = prev[j-arr[i]];
                bool not_take = prev[j];
                temp[j] = take | not_take;
            }
            prev = temp;
        }
        
        return prev[sum];
    }
};