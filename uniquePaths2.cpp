/*Recursion -
TC -> O(2 ^(m + n))
SC -> O(m + n)*/
class Solution {
public:
    int fun(int row, int col, int n, int m, vector<vector<int>>& grid)
    {
        if(row == n-1 && col == m-1) return 1;
        int x = 0;
        if(row + 1 < n && grid[row + 1][col] == 0)
        x = fun(row + 1, col, n, m, grid);
        int y = 0;
        if(col + 1 < m && grid[row][col + 1] == 0)
        y = fun(row, col + 1, n, m, grid);

        return x + y;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        return fun(0,0, n, m, obstacleGrid);
    }
};

/*Memoization
TC -> O(m * n)
SC -> O(m * n) -> dp + O(m + n)-> recursion stack space*/
class Solution {
public:
    int fun(int row, int col, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(row == n-1 && col == m-1) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int x = 0;
        if(row + 1 < n && grid[row + 1][col] == 0)
        x = fun(row + 1, col, n, m, grid, dp);
        int y = 0;
        if(col + 1 < m && grid[row][col + 1] == 0)
        y = fun(row, col + 1, n, m, grid, dp);

        return dp[row][col] = x + y;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(0,0, n, m, obstacleGrid, dp);
    }
};

/*Tabulation ->
TC -> O(n * m)
SC -> O(n * m) -> dp array*/

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
                    dp[i][j] = 1;
                    continue;
                }

                int x = 0;
                if(i - 1 >= 0 && grid[i-1][j] == 0)
                x = dp[i-1][j];
                int y = 0;
                if(j - 1 >= 0 && grid[i][j-1] == 0)
                y = dp[i][j-1];

                dp[i][j] = x + y;
            }
        }
        return dp[n-1][m-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        vector<vector<int>>dp(n,vector<int>(m, 0));
        return fun(n, m, obstacleGrid, dp);
    }
};

/*Space Optimization
TC -> O(n * m)
SC -> O(2 * m)*/
class Solution {
public:
    int fun(int n, int m, vector<vector<int>>& grid)
    {
        vector<int>prev(m);
        prev[0] = 1;
        for(int i = 0; i < n; i++)
        {
            vector<int>temp(m);
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                int x = 0;
                if(i - 1 >= 0 && grid[i-1][j] == 0)
                x = prev[j];
                int y = 0;
                if(j - 1 >= 0 && grid[i][j-1] == 0)
                y = temp[j-1];

                temp[j] = x + y;
            }
            prev = temp;
        }
        return prev[m-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        return fun(n, m, obstacleGrid);
    }
};