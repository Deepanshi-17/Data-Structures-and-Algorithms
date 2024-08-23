/*Recursion ->
TC -> O(2^n)
SC -> O(n)*/
    bool fun(int index, vector<int>& arr, int sum)
    {
        if(sum == 0) return true;
        if(index == 0)
        {
            if(sum == arr[0]) return true;
            return false;
        }
        
        bool take = false;
        if(arr[index] <= sum)
        take = fun(index - 1, arr, sum - arr[index]);
        bool not_take = fun(index - 1, arr, sum);
        return take || not_take;
    }
    
/*Memoization
TC -> O(n * sum)
SC -> O(n * sum) + O(n)*/
class Solution {
public:
    bool fun(int index, vector<int>& arr, int sum, vector<vector<int>>& dp)
    {
        if(sum == 0) return true;
        if(index == 0)
        {
            if(sum == arr[0]) return true;
            return false;
        }
        if(dp[index][sum] != -1) return dp[index][sum];
        bool take = false;
        if(arr[index] <= sum)
        take = fun(index - 1, arr, sum - arr[index], dp);
        bool not_take = fun(index - 1, arr, sum, dp);
        return dp[index][sum] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums)
        sum += it;
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(sum + 1,-1));
        return fun(nums.size() - 1, nums, target, dp);
    }
};

/*Tabulation
TC -> O(n * sum)
SC -> O(n * sum)*/
class Solution {
public:
    bool fun(int index, vector<int>& arr, int sum, vector<vector<int>>& dp)
    {
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        if(arr[0] <= sum)
        dp[0][arr[0]] = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                int take = 0;
                if(arr[i] <= j)
                take = dp[i-1][j-arr[i]];
                int not_take = dp[i-1][j];
                
                dp[i][j] = take || not_take;
            }
        }
        return dp[n-1][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums)
        sum += it;
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(sum + 1));
        return fun(nums.size() - 1, nums, target, dp);
    }
};

/*Space Optimization
TC -> O(n * sum)
SC -> O(sum)*/
class Solution {
public:
    bool fun(int index, vector<int>& arr, int sum)
    {
        vector<int>prev(sum + 1, 0);
        vector<int>temp(sum + 1, 0);
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            prev[0] = 1;
            temp[0] = 1;
        }
        if(arr[0] <= sum)
        {prev[arr[0]] = 1;
        temp[arr[0]] = 1;}
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                int take = 0;
                if(arr[i] <= j)
                take = prev[j-arr[i]];
                int not_take = prev[j];
                
                temp[j] = take || not_take;
            }
            prev = temp;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums)
        sum += it;
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        return fun(nums.size() - 1, nums, target);
    }
};