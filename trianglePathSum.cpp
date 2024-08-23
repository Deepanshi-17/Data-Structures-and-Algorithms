/*Recursion ->
TC -> O(2 ^ (n + n))
SC -> O(n)*/
class Solution {
public:
    int fun(int col, int row, vector<vector<int>>& grid, int n)
    {
        if(row == 0) return grid[row][col];
        int x = 1e9;
        if(row - 1>= 0 && col <= row -1)
        x = grid[row][col] + fun(col, row -1, grid, n);
        int y = 1e9;
        if(row - 1 >=0 && col - 1 <= row - 1 && col - 1>=0)
        y = grid[row][col] + fun(col - 1, row -1, grid, n);

        return min(x,y);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int mini = 1e9;
        for(int i = 0; i < n; i++)
        {
            mini = min(mini, fun(i, n-1, triangle, n));
        }
        return mini;
    }
};

/*Memoization
TC -> O(n * n)
SC -> O(n * n) + O(n) -> recursion stack space
*/
class Solution {
public:
    int fun(int col, int row, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(row == 0) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int x = 1e9;
        if(row - 1>= 0 && col <= row -1)
        x = grid[row][col] + fun(col, row -1, grid, dp);
        int y = 1e9;
        if(row - 1 >=0 && col - 1 <= row - 1 && col - 1>=0)
        y = grid[row][col] + fun(col - 1, row -1, grid, dp);

        return dp[row][col] = min(x,y);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int mini = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i = 0; i < n; i++)
        {
            mini = min(mini, fun(i, n-1, triangle, dp));
        }
        return mini;
    }
};

/*Tabulation ->
TC -> O(n * n)
SC -> O(n * n)*/
class Solution {
public:
    int fun(vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        int n = grid.size();
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <=i; j++)
            {
                int x = 1e9;
                if(i-1 >= 0 && j <= i -1)
                x = grid[i][j] + dp[i-1][j];
                int y = 1e9;
                if(i - 1 >= 0 && j-1 <= i-1 && j-1 >= 0)
                {
                    y = grid[i][j] + dp[i-1][j-1];
                }

                dp[i][j] = min(x,y);
            }
        }

        int mini = 1e9;
        for(int i = 0; i < n; i++)
        {
            mini = min(mini, dp[n-1][i]);
        }
        return mini;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(triangle, dp);
    }
};

/*Space Optimization -> 
TC -> O(n*n)
SC -> O(2*n)*/
class Solution {
public:
    int fun(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<int>prev(n);
        prev[0] = grid[0][0];
        for(int i = 1; i < n; i++)
        {
            vector<int>temp(n);
            for(int j = 0; j <=i; j++)
            {
                int x = 1e9;
                if(i-1 >= 0 && j <= i -1)
                x = grid[i][j] + prev[j];
                int y = 1e9;
                if(i - 1 >= 0 && j-1 <= i-1 && j-1 >= 0)
                {
                    y = grid[i][j] + prev[j-1];
                }

                temp[j] = min(x,y);
            }
            prev = temp;
        }

        int mini = 1e9;
        for(int i = 0; i < n; i++)
        {
            mini = min(mini, prev[i]);
        }
        return mini;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return fun(triangle);
    }
};