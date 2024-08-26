/*
Recursion
TC -> O(2 ^ n)
SC -> O(n)
*/
class Solution {
public:
    int fun(int prev, int index, vector<int>& nums)
    {
        int n = nums.size();
        if(index == n) return 0;
        int take = 0;
        if(prev == -1 || nums[prev] < nums[index])
        take = 1 + fun(index, index + 1, nums);
        int not_take = fun(prev, index + 1, nums);
        return max(take, not_take);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        return fun(-1,0,nums);
    }
};

/*
Memoization
TC -> O(n * n)
SC -> O(n * n) + o(n)
*/
class Solution {
public:
    int fun(int prev, int index, vector<int>& nums, vector<vector<int>>&dp)
    {
        int n = nums.size();
        if(index == n) return 0;
        if(dp[index][prev + 1]!= -1) return dp[index][prev + 1];
        int take = 0;
        if(prev == -1 || nums[prev] < nums[index])
        take = 1 + fun(index, index + 1, nums, dp);
        int not_take = fun(prev, index + 1, nums, dp);
        return dp[index][prev + 1] = max(take, not_take);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(-1,0,nums, dp);
    }
};
