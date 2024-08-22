/*Recursion -> 
TC - > O(2^n)
SC -> O(n)*/

class Solution {
public:
    bool fun(int index, int n, vector<int>& nums, int sum)
    {
        if(sum == 0) return true;
        if(index == 0)
        {
            if(sum == nums[index])
            return true;
            return false;
        }
        bool take = false;
        if(nums[index] <= sum)
        {
            take = fun(index - 1, n, nums, sum - nums[index]);
        }
        bool not_take = fun(index - 1, n, nums, sum);
        return take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        sum += nums[i];
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        return fun(n-1, n, nums, target);
    }
};

/*Memoization ->
TC -> O(N * Sum)
SC -> O(N)-> recursion stack space + O(N* Sum) -> 2-D dp*/

class Solution {
public:
    bool fun(int index, int n, vector<int>& nums, int sum, vector<vector<int>>& dp)
    {
        if(sum == 0) return true;
        if(index == 0)
        {
            if(sum == nums[index])
            return true;
            return false;
        }
        if(dp[index][sum] != -1) return dp[index][sum];
        bool take = false;
        if(nums[index] <= sum)
        {
            take = fun(index - 1, n, nums, sum - nums[index], dp);
        }
        bool not_take = fun(index - 1, n, nums, sum, dp);
        return dp[index][sum] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        sum += nums[i];
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
        return fun(n-1, n, nums, target, dp);
    }
};

/*Tabulation

TC -> O(N * sum)
SC -> O(N*Sum)*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i = 0; i < n; i++)
        target += nums[i];
        if(target % 2 != 0) return false;
        int sum = target / 2;
        vector<vector<int>>dp(n, vector<int>(sum + 1, false));
        if(nums[0] <= sum)
        dp[0][nums[0]] = true;

        for(int i = 0; i < n; i++)
        dp[i][0] = true;

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool take = false;
                if(nums[i] <= j)
                {
                    take = dp[i-1][j-nums[i]];
                }
                bool not_take = dp[i-1][j];
                dp[i][j] = take || not_take;
            }
        }
        return dp[n-1][sum];
    }
};

/*Space Optimization
TC -> O(N * sum)
SC -> O(2 * sum)*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i = 0; i < n; i++)
        target += nums[i];
        if(target % 2 != 0) return false;
        int sum = target / 2;
        vector<int>prev(sum + 1, false);
        vector<int>temp(sum + 1, false);
        if(nums[0] <= sum)
        prev[nums[0]] = true;

        for(int i = 0; i < n; i++)
        {prev[0] = true;
        temp[0] = true;}

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool take = false;
                if(nums[i] <= j)
                {
                    take = prev[j-nums[i]];
                }
                bool not_take = prev[j];
                temp[j] = take || not_take;
            }
            prev = temp;
        }
        return prev[sum];
    }
};