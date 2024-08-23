/*Recursion ->
TC -> O(3 ^ n)
SC -> O(n)*/

class Solution {
public:
    int fun(int row, int col, vector<vector<int>>& grid, int n)
    {
        if(row == 0) return grid[row][col];

        int x = 1e9;
        if(row - 1 >= 0)
        x = grid[row][col] + fun(row - 1, col, grid, n);
        int y = 1e9;
        if(row - 1 >= 0 && col - 1 >= 0)
        y = grid[row][col] + fun(row - 1, col -1 , grid, n);
        int z = 1e9;
        if(row - 1 >= 0 && col + 1 < n)
        z = grid[row][col] + fun(row - 1, col + 1, grid, n);

        return min(x, min(y,z));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int maxi = 1e9;
        for(int i = 0; i < n; i++)
        {
            maxi = min(maxi, fun(n-1, i, matrix, n));
        }
        return maxi;
    }
};

/*Memoization
TC -> O(n * n)
SC -> O(n * n) + O(n)*/
class Solution {
public:
    int fun(int row, int col, vector<vector<int>>& grid, int n, vector<vector<int>>& dp)
    {
        if(row == 0) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int x = 1e9;
        if(row - 1 >= 0)
        x = grid[row][col] + fun(row - 1, col, grid, n, dp);
        int y = 1e9;
        if(row - 1 >= 0 && col - 1 >= 0)
        y = grid[row][col] + fun(row - 1, col -1 , grid, n, dp);
        int z = 1e9;
        if(row - 1 >= 0 && col + 1 < n)
        z = grid[row][col] + fun(row - 1, col + 1, grid, n, dp);

        return dp[row][col] = min(x, min(y,z));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int maxi = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i = 0; i < n; i++)
        {
            maxi = min(maxi, fun(n-1, i, matrix, n, dp));
        }
        return maxi;
    }
};

/*Tabulation 
TC -> O(n * n)
SC -> O(n * n)*/
class Solution {
public:
    int fun(vector<vector<int>>& grid, int n, vector<vector<int>>& dp)
    {
        for(int i = 0; i < n; i++)
        {
            dp[0][i] = grid[0][i];
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x = 1e9;
                if(i-1 >= 0)
                x = grid[i][j] + dp[i-1][j];

                int y = 1e9;
                if(i - 1 >= 0 && j - 1 >= 0)
                y = grid[i][j] + dp[i-1][j-1];

                int z = 1e9;
                if(i - 1 >= 0 && j + 1 < n)
                z = grid[i][j] + dp[i-1][j+1];

                dp[i][j] = min(x,min(y,z));
            }

        }
        int maxi = 1e9;
        for(int i = 0; i < n; i++)
        {
            maxi = min(maxi, dp[n-1][i]);
        }
        return maxi;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n));
        return fun(matrix, n, dp);
    }
};

/*Space Optimization
TC ->O(n * n)
SC -> O(n)*/
class Solution {
public:
    int fun(vector<vector<int>>& grid, int n)
    {
        vector<int>prev(n);
        for(int i = 0; i < n; i++)
        {
            prev[i] = grid[0][i];
        }

        for(int i = 1; i < n; i++)
        {
            vector<int>temp(n);
            for(int j = 0; j < n; j++)
            {
                int x = 1e9;
                if(i-1 >= 0)
                x = grid[i][j] + prev[j];

                int y = 1e9;
                if(i - 1 >= 0 && j - 1 >= 0)
                y = grid[i][j] + prev[j-1];

                int z = 1e9;
                if(i - 1 >= 0 && j + 1 < n)
                z = grid[i][j] + prev[j+1];

                temp[j] = min(x,min(y,z));
            }

            prev = temp;

        }
        int maxi = 1e9;
        for(int i = 0; i < n; i++)
        {
            maxi = min(maxi, prev[i]);
        }
        return maxi;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        return fun(matrix, n);
    }
};