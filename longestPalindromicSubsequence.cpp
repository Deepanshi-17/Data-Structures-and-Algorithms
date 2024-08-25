/*Recursion
 TC -> O(2^(n + n))
 SC -> O(n + n)
 */
 class Solution {
public:
    int fun(int n, int m, string s, string r)
    {
        if(n < 0 || m < 0) return 0;
        if(s[n] == r[m]) 
        return 1 + fun(n-1, m-1, s, r);
        return max(fun(n-1, m, s, r), fun(n, m-1, s, r));
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(s.begin(), s.end());
        int n = s.length();
        return fun(n-1, n-1, s, r);
    }
};

/*Memoization 
TC -> O(n * n)
SC -> O(n * n) + O(n + n)
*/
class Solution {
public:
    int fun(int n, int m, string s, string r, vector<vector<int>>& dp)
    {
        if(n < 0 || m < 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n] == r[m]) 
        return 1 + fun(n-1, m-1, s, r, dp);
        return dp[n][m] = max(fun(n-1, m, s, r, dp), fun(n, m-1, s, r, dp));
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(s.begin(), s.end());
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(n-1, n-1, s, r, dp);
    }
};

/*Tabulation
TC -> O(n log n) + O(n * n)
SC -> O(n * n)
*/
class Solution {
public:
    int fun(string s, string r, vector<vector<int>>& dp)
    {
        int n = s.length();
        int m = r.length();
        for(int i = 0; i <=n; i++)
        {
            dp[i][0] = 0;
        }
        for(int i = 0; i <=m; i++)
        {
            dp[0][i] = 0;
        }

        for(int i = 1; i <=n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == r[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(s.begin(), s.end());
        int n = s.length();
        vector<vector<int>>dp(n + 1,vector<int>(n + 1));
        return fun(s, r, dp);
    }
};

/*Space Optimization
TC -> O(nlogn) + O(n * n)
SC -> O(2 * n)
*/
class Solution {
public:
    int fun(string s, string r)
    {
        int n = s.length();
        int m = r.length();
        vector<int>prev(m+1);
        for(int i = 0; i <=n; i++)
        {
            prev[0] = 0;
        }
        for(int i = 0; i <=m; i++)
        {
            prev[i] = 0;
        }

        for(int i = 1; i <=n; i++)
        {
            vector<int>temp(m+1);
            temp[0] = 0;
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == r[j-1])
                temp[j] = 1 + prev[j-1];
                else
                temp[j] = max(temp[j-1], prev[j]);
            }
            prev = temp;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(s.begin(), s.end());
        int n = s.length();
        return fun(s, r);
    }
};