/*Recursion
TC -> O(2 ^ (n + m))
SC -> O(n + m)
*/
class Solution {
public:
    bool isAllStars(string& p, int m)
    {
        for(int i = 0; i <=m; i++)
        {
            if(p[i] != '*')
            return false;
        }
        return true;
    }
    bool fun(int n, int m, string &s, string &p)
    {
        if(n < 0 && m < 0) return true;
        if(m < 0 && n >= 0) return false;
        if(n < 0 && m >= 0) return isAllStars(p,m);

        if(s[n] == p[m] || p[m] == '?')
        return fun(n-1, m-1, s, p);
        if(p[m] == '*') return fun(n,m-1, s, p) || fun(n-1,m, s, p);
        else return false;

    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        return fun(n, m, s, p);
    }
};

/*Memoization
TC -> o(n * m)
SC -> o(n * m) + O(n + m)
*/
class Solution {
public:
    bool isAllStars(string& p, int m)
    {
        for(int i = 0; i <=m; i++)
        {
            if(p[i] != '*')
            return false;
        }
        return true;
    }
    bool fun(int n, int m, string &s, string &p, vector<vector<int>>& dp)
    {
        if(n < 0 && m < 0) return true;
        if(m < 0 && n >= 0) return false;
        if(n < 0 && m >= 0) return isAllStars(p,m);
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n] == p[m] || p[m] == '?')
        return dp[n][m] = fun(n-1, m-1, s, p, dp);
        if(p[m] == '*') return dp[n][m] = fun(n,m-1, s, p, dp) || fun(n-1,m, s, p, dp);
        else return dp[n][m] = false;

    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(n-1, m-1, s, p, dp);
    }
};

/*Tabulation
TC -> O(n * m)
SC -> O(n * m)*/
class Solution {
public:
    bool isAllStars(string& p, int m)
    {
        for(int i = 0; i <=m; i++)
        {
            if(p[i] != '*')
            return false;
        }
        return true;
    }
    bool fun(int n, int m, string &s, string &p, vector<vector<bool>>& dp)
    {
        for(int i = 1; i <=n; i++)
        {
            dp[i][0] = false;
        }
        for(int j = 1; j <=m; j++)
        {
            dp[0][j] = isAllStars(p,j-1);
        }
        dp[0][0] = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') 
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1));
        return fun(n, m, s, p, dp);
    }
};

/*Space Optimization
TC -> O(n * m)
SC -> O(2 * m)
*/
class Solution {
public:
    bool isAllStars(string& p, int m)
    {
        for(int i = 0; i <=m; i++)
        {
            if(p[i] != '*')
            return false;
        }
        return true;
    }
    bool fun(int n, int m, string &s, string &p)
    {
        vector<bool>prev(m+1);
        for(int j = 1; j <=m; j++)
        {
            prev[j] = isAllStars(p,j-1);
        }
        prev[0] = true;
        for(int i = 1; i <= n; i++)
        {
            vector<bool>temp(m+1);
            temp[0] = false;
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                temp[j] = prev[j-1];
                else if(p[j-1] == '*') 
                temp[j] = temp[j-1] || prev[j];
                else temp[j] = false;
            }
            prev = temp;
        }

        return prev[m];
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        return fun(n, m, s, p);
    }
};
