/*Recursion ->
TC -> O(2^ (m + n))
SC -> O(m + n)*/

class Solution {
public:
    int fun(int row, int col, int m, int n)
    {
        if(row == m-1 && col == n-1) return 1;
        int x = 0;
        if(row + 1 < m)
        x = fun(row + 1, col, m, n);
        int y = 0;
        if(col + 1 < n)
        y = fun(row, col + 1, m, n);
        return x + y;
    }
    int uniquePaths(int m, int n) {
        return fun(0, 0, m, n);
    }
};

/*Memoization
TC -> O(m * n)
SC -> O(m + n) -> recursion stack space + O(m * n) -> dp array*/

class Solution {
public:
    int fun(int row, int col, int m, int n, vector<vector<int>>& dp)
    {
        if(row == m-1 && col == n-1) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int x = 0;
        if(row + 1 < m)
        x = fun(row + 1, col, m, n, dp);
        int y = 0;
        if(col + 1 < n)
        y = fun(row, col + 1, m, n, dp);
        return dp[row][col] = x + y;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(0, 0, m, n, dp);
    }
};

/*Tabulation -> 
TC -> O(m * n)
SC -> O(m * n) -> dp array*/

class Solution {
public:
    int fun(int m, int n, vector<vector<int>>& dp)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if( i == 0 && j == 0)
                {
                    dp[0][0] = 1;
                    continue;
                }
                int x = 0;
                if(i - 1>= 0)
                x = dp[i-1][j];
                int y = 0;
                if(j - 1>= 0)
                y = dp[i][j-1];

                dp[i][j] = x + y;
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n));
        return fun(m, n, dp);
    }
};

/*Space Optimization
TC -> O(m * n)
SC -> O(2 * n)*/
class Solution {
public:
    int fun(int m, int n)
    {
        vector<int>prev(n);
        prev[0] = 1;
        for(int i = 0; i < m; i++)
        {
            vector<int>temp(n);
            for(int j = 0; j < n; j++)
            {
                if( i == 0 && j == 0)
                {
                    temp[0] = 1;
                    continue;
                }
                int x = 0;
                if(i - 1>= 0)
                x = prev[j];
                int y = 0;
                if(j - 1>= 0)
                y = temp[j-1];

                temp[j] = x + y;
            }
            prev = temp;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        return fun(m, n);
    }
};