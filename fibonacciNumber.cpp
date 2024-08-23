/*Recursion->
TC -> O(2^n)
SC -> O(n)
 */

    int mod = 1e9 + 7;
    long long fun(int n)
    {
        if(n <= 1) return n;
        return fun(n-1) + fun(n-2);
    }
    long long int topDown(int n) {
        return fun(n) % mod;
    }

/*Memoization ->
TC -> O(N)
SC -> o(N)*/
    int mod = 1e9 + 7;
    long long fun(int n, vector<long long int>& dp)
    {
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (fun(n-1, dp) + fun(n-2, dp))%mod;
    }
    long long int topDown(int n) {
        vector<long long int>dp(n+1,-1);
        return fun(n, dp);
    }

/*Tabulation ->
TC -> O(N)
SC -> O(N)*/

    long long int bottomUp(int n) {
        vector<long long int>dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <=n; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        return dp[n];
    }

/*Space Optimization->
TC -> O(N)
SC -> O(2) */

    long long int bottomUp(int n) {
        long long int prev2 = 0;
        long long int prev = 1;
        for(int i = 2; i <=n; i++)
        {
            long long int curr = (prev + prev2)%mod;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }