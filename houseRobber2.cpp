/*Recursion ->
TC -> O(2^n)
SC -> O(n)*/

class Solution {
public:
    int fun(int index, vector<int>& nums)
    {
        if(index == 0) return nums[0];
        if(index == 1) return max(nums[0], nums[1]);
        int take = -1e9;
        if(index - 2 >= 0) take =  nums[index] + fun(index - 2, nums);
        int not_take = fun(index - 1, nums);
        return max(take , not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>v1;
        vector<int>v2;
        for(int i = 0; i < n; i++)
        {
            if(i != 0)
            v1.push_back(nums[i]);
            if(i != n - 1)
            v2.push_back(nums[i]);
        }
        int x = fun(v1.size() - 1, v1);
        int y = fun(v2.size() - 1, v2);
        return max(x,y);
    }
};

/*Memoization 
TC -> O(n)
SC -> O(n) + O(n)*/
class Solution {
public:
    int fun(int index, vector<int>& nums, vector<int>& dp)
    {
        if(index == 0) return nums[0];
        if(index == 1) return max(nums[0], nums[1]);
        if(dp[index] != -1) return dp[index];
        int take = -1e9;
        if(index - 2 >= 0) take =  nums[index] + fun(index - 2, nums, dp);
        int not_take = fun(index - 1, nums, dp);
        return dp[index] = max(take , not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>v1;
        vector<int>v2;
        for(int i = 0; i < n; i++)
        {
            if(i != 0)
            v1.push_back(nums[i]);
            if(i != n - 1)
            v2.push_back(nums[i]);
        }
        vector<int>dp(n-1,-1);
        vector<int>dp2(n-1, -1);
        int x = fun(v1.size() - 1, v1, dp);
        int y = fun(v2.size() - 1, v2, dp2);
        return max(x,y);
    }
};

/*Tabulation 
TC -> O(n)
SC -> O(n) -> dp array*/
class Solution {
public:
        int fun(vector<int>& nums, vector<int>&dp) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for(int i = 2; i < n; i++)
        {
            int take = -1e9;
            if(i - 2 >= 0)
            take = nums[i] + dp[i-2];
            int not_take = dp[i-1];
            dp[i] = max(take, not_take);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>v1;
        vector<int>v2;
        for(int i = 0; i < n; i++)
        {
            if(i != 0)
            v1.push_back(nums[i]);
            if(i != n - 1)
            v2.push_back(nums[i]);
        }
        vector<int>dp(n-1);
        vector<int>dp2(n-1);
        int x = fun(v1, dp);
        int y = fun(v2, dp2);
        return max(x,y);
    }
};

/*Space Optimization
TC -> O(n)
SC -> O(2)*/

class Solution {
public:
    int fun(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        int prev2 = nums[0];
        int prev = max(nums[1], nums[0]);
        for(int i = 2; i < n; i++)
        {
            int take = -1e9;
            if(i - 2 >= 0)
            take = nums[i] + prev2;
            int not_take = prev;
            int curr = max(take, not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>v1;
        vector<int>v2;
        for(int i = 0; i < n; i++)
        {
            if(i != 0)
            v1.push_back(nums[i]);
            if(i != n - 1)
            v2.push_back(nums[i]);
        }
        int x = fun(v1);
        int y = fun(v2);
        return max(x,y);
    }
};