/*Recursion
TC -> O( 2^(m + n))
SC -> O(n + m)
*/
class Solution {
public:
    int fun(int n, int m , string s, string r)
    {
        if(n < 0 || m < 0) return 0;
        if(s[n] == r[m])
        return 1 + fun(n-1, m-1, s, r);
        return max(fun(n-1, m, s, r), fun(n, m-1, s, r));
    }
    int minInsertions(string s) {
        int n = s.length();
        string r = s;
        reverse(s.begin(), s.end());
        return n - fun(n-1, n-1, s, r);
    }
};

/*Memoization
TC -> O(n * m)
SC -> O(n + m)
*/
class Solution {
public:
    int fun(int n, int m , string &s, string &r, vector<vector<int>>& dp)
    {
        if(n < 0 || m < 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n] == r[m])
        return dp[n][m] = 1 + fun(n-1, m-1, s, r, dp);
        return dp[n][m] = max(fun(n-1, m, s, r, dp), fun(n, m-1, s, r, dp));
    }
    int minInsertions(string s) {
        int n = s.length();
        string r = s;
        reverse(s.begin(), s.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return n - fun(n-1, n-1, s, r, dp);
    }
};

/*Tabulation ->
TC -> O(n * n)
SC -> O(n * n)
*/
class Solution {
public:
int fun(int n, int m, string text1, string text2, vector<vector<int>>& dp)
    {
        for(int i = 0; i <=n; i++)
        dp[i][0] = 0;
        for(int j = 0; j <=m; j++)
        dp[0][j] = 0;
        
        for(int i = 1; i <=n; i++)
        {
            for(int j = 1; j <=m; j++)
            {
                if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
    int minInsertions(string s) {
        int n = s.length();
        string r = s;
        reverse(s.begin(), s.end());
        vector<vector<int>>dp(n + 1, vector<int>(n + 1));
        return n - fun(n, n, s, r, dp);
    }
};

/*Space Optimization
TC -> O(n * n)
SC -> O(2 * n)
*/
class Solution {
public:
    int fun(int n, int m, string text1, string text2)
    {
        vector<int>prev(m+1);
        for(int i = 0; i <=n; i++)
        prev[0] = 0;
        for(int j = 0; j <=m; j++)
        prev[j] = 0;
        
        for(int i = 1; i <=n; i++)
        {
            vector<int>temp(m+1);
            temp[0] = 0;
            for(int j = 1; j <=m; j++)
            {
                if(text1[i-1] == text2[j-1])
                temp[j] = 1 + prev[j-1];
                else
                temp[j] = max(temp[j-1], prev[j]);
            }
            prev = temp;
        }
        return prev[m];
    }
    int minInsertions(string s) {
        int n = s.length();
        string r = s;
        reverse(s.begin(), s.end());
        return n - fun(n, n, s, r);
    }
};