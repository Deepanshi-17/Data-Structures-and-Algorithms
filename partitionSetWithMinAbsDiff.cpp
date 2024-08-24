/*Recursion Approach 
TC -> O(2 ^n)
SC -> O(n)
*/
class Solution {
public:
    bool fun(int index, vector<int>& nums, int sum) {
        if (sum == 0) return true;
        if (index == 0) return nums[0] == sum;
        bool take = false;
        if (nums[index] <= sum)
            take = fun(index - 1, nums, sum - nums[index]);
        bool not_take = fun(index - 1, nums, sum);
        return take || not_take;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto it : nums)
            sum += it;
        int maxi = 1e9;
        for (int i = 0; i <= sum; i++) {
            if (fun(n - 1, nums, i))
                maxi = min(maxi, abs(i - (sum - i)));
        }
        return maxi;
    }
};

/*Memoization Approach
TC -> O(n * sum)
SC  O(n * sum) -> dp array + O(n)->
*/
class Solution {
public:
    bool fun(int index, vector<int>& nums, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (index == 0) return nums[0] == sum;
        if(dp[index][sum] != -1) return dp[index][sum];
        bool take = false;
        if (nums[index] <= sum)
            take = fun(index - 1, nums, sum - nums[index], dp);
        bool not_take = fun(index - 1, nums, sum, dp);
        return dp[index][sum] = take || not_take;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto it : nums)
            sum += it;
        int maxi = 1e9;
        for (int i = 0; i <= sum; i++) {
            vector<vector<int>>dp(n,vector<int>(i+1, -1));
            if (fun(n - 1, nums, i, dp))
                maxi = min(maxi, abs(i - (sum - i)));
        }
        return maxi;
    }
};

/*Tabulation
TC -> O(n * sum)
SC ->  O(n * sum)*/

class Solution {
public:
    void fun(vector<int>& nums, int sum, vector<vector<int>>& dp) {
        int n = nums.size();
     for(int i = 0; i < n; i++)
     dp[i][0] = 1;
     
     if(nums[0] <= sum)
     dp[0][nums[0]] = 1;
     
     for(int i = 1; i < n; i++)
     {
         for(int j = 1; j <= sum; j++)
         {
             int take = 0;
             if(nums[i] <= j)
             take = dp[i-1][j-nums[i]];
             int not_take = dp[i-1][j];
             
             dp[i][j] = take || not_take;
         }
     }
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto it : nums)
            sum += it;
        vector<vector<int>>dp(n,vector<int>(sum + 1, 0));
        fun(nums, sum, dp);
        int maxi = 1e9;
        for(int i = 0; i <= sum; i++)
        {
            if(dp[n-1][i] == 1)
            maxi = min(maxi, abs(i-(sum-i)));
        }
        return maxi;
    }
};

/*Space Optimization
TC -> O(n * sum)
SC ->  O(2 * sum)*/

class Solution {
public:
    void fun(vector<int>& nums, int sum, vector<int>& prev) {
         vector<int>temp(sum + 1, 0);
        int n = nums.size();
     for(int i = 0; i < n; i++)
     {
         prev[0] = 1;
         temp[0] = 1;
     }
     
     if(nums[0] <= sum)
     {
        prev[nums[0]] = 1;
        temp[nums[0]] = 1;
     }
     
     for(int i = 1; i < n; i++)
     {
         for(int j = 1; j <= sum; j++)
         {
             int take = 0;
             if(nums[i] <= j)
             take = prev[j-nums[i]];
             int not_take = prev[j];
             
             temp[j] = take || not_take;
         }
         prev = temp;
     }
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto it : nums)
            sum += it;
        vector<int>prev(sum + 1, 0);
        fun(nums, sum, prev);
        int maxi = 1e9;
        for(int i = 0; i <= sum; i++)
        {
            if(prev[i] == 1)
            maxi = min(maxi, abs(i-(sum-i)));
        }
        return maxi;
    }
};