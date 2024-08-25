/*Recursion
TC -> O(2 ^ (n + m))
SC -> O(n + m)
*/
class Solution {
public:
    int fun(int i, int j, string &text1, string &text2)
    {
        if(i < 0 || j < 0) return 0;
        if(text1[i] == text2[j])
        {
            return 1 + fun(i-1, j-1, text1, text2);
        }
        return max(fun(i, j-1, text1, text2), fun(i-1, j, text1, text2));
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int x = fun(n-1, m-1, word1, word2);
        return (n - x) + (m - x);
    }
};

/*Memoization
TC -> O(n * m)
SC -> O(n * m) + O(n + m)
*/
class Solution {
public:
    int fun(int i, int j, string &text1, string &text2, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j])
        {
            return dp[i][j] = 1 + fun(i-1, j-1, text1, text2, dp);
        }
        return dp[i][j] = max(fun(i, j-1, text1, text2, dp), fun(i-1, j, text1, text2, dp));
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        int x = fun(n-1, m-1, word1, word2, dp);
        return (n - x) + (m - x);
    }
};

/*
Tabulation
TC -> O(n * m)
SC -> O(n * m)
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
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        int x = fun(n, m, word1, word2, dp);
        return (n - x) + (m - x);
    }
};

/*
Space Optimization
TC -> O(n * m)
SC -> O(n * m)
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
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int x = fun(n, m, word1, word2);
        return (n - x) + (m - x);
    }
};