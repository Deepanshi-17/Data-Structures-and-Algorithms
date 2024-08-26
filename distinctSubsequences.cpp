/*Recursion
TC -> O(2 ^ (n + m)) -> exponential
SC -> O(n + m) recursion stack space
*/
class Solution {
public:
    int fun(int indexs, int indext, string &s, string &t)
    {
        if(indext < 0) return 1;
        if(indexs < 0) return 0;
        if(s[indexs] == t[indext]) return fun(indexs-1, indext-1, s, t) + fun(indexs - 1, indext, s, t);
        return fun(indexs - 1, indext, s, t);
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        return fun(n-1, m-1, s, t);
    }
};

/*Memoization
TC ->
SC -> O(n * m) -> 2-D DP array + O(n + m) -> recursion stack space
*/
class Solution {
public:
    int fun(int indexs, int indext, string &s, string &t, vector<vector<int>>& dp)
    {
        if(indext < 0) return 1;
        if(indexs < 0) return 0;
        if(dp[indexs][indext] != -1) return dp[indexs][indext];
        if(s[indexs] == t[indext]) return dp[indexs][indext] = fun(indexs-1, indext-1, s, t, dp) + fun(indexs - 1, indext, s, t, dp);
        return dp[indexs][indext] = fun(indexs - 1, indext, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(n-1, m-1, s, t, dp);
    }
};

/*Tabulation
TC -> O(n * m)
SC -> O(n * m)
*/
class Solution {
public:
    long long fun(int n, int m, string &s, string &t, vector<vector<int>>& dp)
    {
        for(int i = 0; i <=m; i++)
        {
            dp[0][i] = 0;
        }
        for(int i = 0; i <=n; i++)
        {
            dp[i][0] = 1;
        }

        for(int i=1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1]){
                long long sum = dp[i-1][j-1];
                sum += dp[i-1][j];
                dp[i][j] = (int) sum;
                }
                else
                dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        return fun(n, m, s, t, dp);
    }
};

/*Space Optimization
TC -> O(n * m)
SC -> O(2 * m)
*/
class Solution {
public:
    long long fun(int n, int m, string &s, string &t)
    {
        vector<int>prev(m+1,0);
        for(int i = 0; i <=m; i++)
        {
            prev[i] = 0;
        }
        for(int i = 0; i <=n; i++)
        {
            prev[0] = 1;
        }

        for(int i=1; i <= n; i++)
        {
            vector<int>temp(m+1,0);
            temp[0] = 1;
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1]){
                long long sum = prev[j-1];
                sum += prev[j];
                temp[j] = (int) sum;
                }
                else
                temp[j] = prev[j];
            }
            prev = temp;
        }
        return prev[m];
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        return fun(n, m, s, t);
    }
};