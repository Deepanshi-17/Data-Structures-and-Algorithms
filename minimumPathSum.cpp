/*Recursion
TC-> O(2 ^ (m + n))
SC-> O(m + n)*/
class Solution {
public:
    int fun(int row, int col, int n, int m, vector<vector<int>>& grid)
    {
        if(row == n-1 && col == m-1)
        return grid[row][col];

        int x = 1e9;
        if(row + 1 < n)
        x = grid[row][col] + fun(row + 1, col , n, m, grid);
        int y = 1e9;
        if(col + 1 < m)
        y = grid[row][col] + fun(row, col + 1, n, m, grid);
        return min(x,y);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return fun(0,0, n, m, grid);
    }
};

/*Memoization ->
TC -> O(n * m)
SC -> O(n * m) ->dp array + O(n + m) -> recursion stack space*/
class Solution {
public:
    int fun(int row, int col, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(row == n-1 && col == m-1)
        return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int x = 1e9;
        if(row + 1 < n)
        x = grid[row][col] + fun(row + 1, col , n, m, grid, dp);
        int y = 1e9;
        if(col + 1 < m)
        y = grid[row][col] + fun(row, col + 1, n, m, grid, dp);
        return dp[row][col] = min(x,y);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(0,0, n, m, grid, dp);
    }
};

/*Tabulation ->
TC -> O(n * m)
SC -> O(n * m)
*/
class Solution {
public:
    int fun(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int x = 1e9;
                if(i - 1 >= 0)
                x = grid[i][j] + dp[i-1][j];
                int y = 1e9;
                if(j - 1 >= 0)
                y = grid[i][j] + dp[i][j-1];

                dp[i][j] = min(x,y);
            }

        }
        return dp[n-1][m-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        return fun(n, m, grid, dp);
    }
};

/*Space Optimization ->
TC -> O(n * m)
SC -> O(2 * m)*/

class Solution {
public:
    int fun(int n, int m, vector<vector<int>>& grid)
    {
        vector<int>prev(m);
        for(int i = 0; i < n; i++)
        {
            vector<int>temp(m);
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                {
                    temp[j] = grid[i][j];
                    continue;
                }
                int x = 1e9;
                if(i - 1 >= 0)
                x = grid[i][j] + prev[j];
                int y = 1e9;
                if(j - 1 >= 0)
                y = grid[i][j] + temp[j-1];

                temp[j] = min(x,y);
            }
            prev = temp;
        }
        return prev[m-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return fun(n, m, grid);
    }
};