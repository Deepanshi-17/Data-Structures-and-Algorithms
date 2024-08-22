/*
RECURSION
TC -> O(3^N + N)
SC -> O(N)
*/
class Solution {
public:
    int fun(int row, int col, vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        if(row < 0 || col < 0 || col >= n) return 1e9;
        if(row == 0) return matrix[row][col];
        int x = matrix[row][col] + fun(row - 1, col, matrix);
        int y = matrix[row][col] + fun(row - 1, col + 1, matrix);
        int z = matrix[row][col] + fun(row - 1, col - 1, matrix);

        return min(x,min(y,z));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        for(int i = 0; i < n; i++)
        {
            for (int i = 0; i < n; i++) {
            mini = min(mini, fun(n-1, i, matrix));  // Start from the last row (n-1)
        }
        }
        return mini;
    }
};

/*Memoization
TC-> O(N*N)
SC-> O(N*N)-> DP & O(N)-> RECURSION STACK SPACE
 */
 class Solution {
public:
    int fun(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        int n = matrix.size();
        if(row < 0 || col < 0 || col >= n) return 1e9;
        if(dp[row][col] != -1) return dp[row][col];
        if(row == 0) return dp[row][col] = matrix[row][col];
        int x = matrix[row][col] + fun(row - 1, col, matrix, dp);
        int y = matrix[row][col] + fun(row - 1, col + 1, matrix, dp);
        int z = matrix[row][col] + fun(row - 1, col - 1, matrix, dp);

        return dp[row][col] = min(x,min(y,z));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i = 0; i < n; i++)
        {
            for (int i = 0; i < n; i++) {
            mini = min(mini, fun(n-1, i, matrix, dp));  // Start from the last row (n-1)
        }
        }
        return mini;
    }
};

/*
TABULATION->
TC-> O(N*N)
SC-> O(N*N)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n));

        for(int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++) 
            {
                int x = 1e9;
                if(i-1 >= 0)
                x =  dp[i-1][j];
                int y = 1e9;
                if(i- 1>=0 && j-1>=0)
                y = dp[i-1][j-1];
                int z = 1e9;
                if(i-1 >=0 && j + 1 < n)
                z = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + min(x, min(y,z));
            }
        }
        int mini = 1e9;
        for(int i = 0; i < n; i++)
        {
            mini = min(mini, dp[n-1][i]);
        }
        return mini;
    }
};

/*Space Optimization
TC -> O(N*N)
SC -> O(N*2) */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev(n);
        for(int i = 0; i < n; i++)
        {
            prev[i] = matrix[0][i];
        }
        for(int i = 1; i < n; i++)
        {
            vector<int>temp(n);
            for (int j = 0; j < n; j++) 
            {
                int x = 1e9;
                if(i-1 >= 0)
                x =  prev[j];
                int y = 1e9;
                if(i- 1>=0 && j-1>=0)
                y = prev[j-1];
                int z = 1e9;
                if(i-1 >=0 && j + 1 < n)
                z = prev[j+1];

                temp[j] = matrix[i][j] + min(x, min(y,z));
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
};