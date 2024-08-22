/*Tabulation->
TC -> O(N) + O(N) + O(N * nums.sum) + O(nums.sum) 
SC -> O(N * nums.sum)*/

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        sum  += nums[i];

        vector<vector<bool>>dp(n, vector<bool>(sum + 1, false));
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
                take = dp[i-1][j-nums[i]];
                bool not_take = dp[i-1][j];
                dp[i][j] = take || not_take;
            }
        }
        int maxi = 1e9;
        for(int i = 0; i <= sum; i++)
        {
            if(dp[n-1][i] == true)
            {
                maxi = max(maxi, abs(i - (sum - i)));
            }
        }
        return maxi;
    }
};

/*Space Optimization ->
TC -> O(N) + O(N) + O(N * nums.sum) + O(nums.sum) 
SC -> O(2 * nums.sum)*/

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        sum  += nums[i];

        vector<bool>prev(sum + 1, false);
        vector<bool>temp(sum + 1, false);
        if(nums[0] <= sum)
        prev[nums[0]] = true;

        for(int i = 0; i < n; i++){
        prev[0] = true;
        temp[0] = true;}

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool take = false;
                if(nums[i] <= j)
                take = prev[j-nums[i]];
                bool not_take = prev[j];
                temp[j] = take || not_take;
            }
            prev = temp;
        }
        int maxi = 1e9;
        for(int i = 0; i <= sum; i++)
        {
            if(prev[i] == true)
            {
                maxi = max(maxi, abs(i - (sum - i)));
            }
        }
        return maxi;
    }
};