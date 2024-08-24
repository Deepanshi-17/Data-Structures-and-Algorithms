/*Recursion ->
TC -> O(2 ^ n)
SC -> O(n)
*/
#include<bits/stdc++.h>
class Solution {
public:
    int fun(int index, vector<int>& nums, int sum)
    {
        if(index == 0)
        {
            if(sum == 0 && nums[0] == 0) return 2;
            if(sum == 0 || nums[0] == sum) return 1;
            return 0;
        }

        int take = 0;
        if(nums[index] <= sum) take = fun(index - 1, nums, sum - nums[index]);
        int not_take = fun(index - 1, nums, sum);
        return take + not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        /*s1 - s2 = d
        s1 + s2 = totsum
        s1 = d + totsum / 2*/
        int n = nums.size();
        int totsum = 0;
        for(auto it: nums) totsum += it;
        if((target + totsum) % 2 != 0) return 0;
        int sum = (target + totsum) / 2;

        return fun(n-1, nums, sum);
    }
};

/*Memoization ->
TC -> O(n * sum)
SC -> O(n * sum) + O(n)
*/
#include<bits/stdc++.h>
class Solution {
public:
    int fun(int index, vector<int>& nums, int sum, vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if(sum == 0 && nums[0] == 0) return  dp[index][sum] = 2;
            if(sum == 0 || nums[0] == sum) return  dp[index][sum] = 1;
            return  dp[index][sum] = 0;
        }
        if( dp[index][sum] != -1) return  dp[index][sum];
        int take = 0;
        if(nums[index] <= sum) take = fun(index - 1, nums, sum - nums[index], dp);
        int not_take = fun(index - 1, nums, sum, dp);
        return dp[index][sum] = take + not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        /*s1 - s2 = d
        s1 + s2 = totsum
        s1 = d + totsum / 2*/
        int n = nums.size();
        int totsum = 0;
        for(auto it: nums) totsum += it;
        if((target + totsum) % 2 != 0 || (target + totsum < 0)) return 0;
        int sum = (target + totsum) / 2;
        vector<vector<int>>dp(n,vector<int>(sum + 1, -1));
        return fun(n-1, nums, sum, dp);
    }
};

/*Tabulation->
TC -> O(N * Sum)
SC -> O(N * Sum)
*/

#include<bits/stdc++.h>
class Solution {
public:
    int fun(int n, vector<int>& nums, int sum, vector<vector<int>>& dp)
    {

        for(int i = 0; i < n; i++)
        dp[i][0] = 1;

        if(nums[0] <= sum)
        dp[0][nums[0]] = 1;

        if(nums[0] == 0) dp[0][0] = 2;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                int take = 0;
                if(nums[i] <= j)
                take = dp[i-1][j-nums[i]];
                int not_take = dp[i-1][j];
                dp[i][j] = take + not_take;
            }
        }
        return dp[n-1][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        /*s1 - s2 = d
        s1 + s2 = totsum
        s1 = d + totsum / 2*/
        int n = nums.size();
        int totsum = 0;
        for(auto it: nums) totsum += it;
        if((target + totsum) % 2 != 0 || (target + totsum < 0)) return 0;
        int sum = (target + totsum) / 2;
        vector<vector<int>>dp(n,vector<int>(sum + 1, 0));
        return fun(n, nums, sum, dp);
    }
};

/*Space Optimization ->
TC -> O(N* sum)
SC -> O(2 * Sum)
*/
#include<bits/stdc++.h>
class Solution {
public:
    int fun(int n, vector<int>& nums, int sum)
    {
        vector<int>prev (sum + 1, 0);
        for(int i = 0; i < n; i++)
        prev[0] = 1;

        if(nums[0] <= sum)
        prev[nums[0]] = 1;

        if(nums[0] == 0) prev[0] = 2;

        for(int i = 1; i < n; i++)
        {
            vector<int>temp(sum + 1, 0);
            for(int j = 0; j <= sum; j++)
            {
                int take = 0;
                if(nums[i] <= j)
                take = prev[j-nums[i]];
                int not_take = prev[j];
                temp[j] = take + not_take;
            }
            prev = temp;
        }
        return prev[sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        /*s1 - s2 = d
        s1 + s2 = totsum
        s1 = d + totsum / 2*/
        int n = nums.size();
        int totsum = 0;
        for(auto it: nums) totsum += it;
        if((target + totsum) % 2 != 0 || (target + totsum < 0)) return 0;
        int sum = (target + totsum) / 2;
        return fun(n, nums, sum);
    }
};