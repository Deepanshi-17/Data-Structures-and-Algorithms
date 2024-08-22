/*

QUESTION-> Given a triangle array, return the minimum path sum from top to bottom.

RECURSION SOLUTION-> 

(BASE CASE WHEN YOU REACH THE TOP OF THE TRIANGULAR GRID AND CAN START FROM ANYWHERE AT THE BOTTOM)
If(row > col || row < 0 || col < 0) return maximum because that can't be the answer.
move to the above row either on the same column (i) or (i - 1)th column.

TC -> O(2^(N*N))
SC -> O(N)
*/

class Solution {
public:
    int fun(int row, int col, vector<vector<int>>& triangle)
    {
        if(col > row || row < 0 || col < 0) return 1e9;
        if(row == 0) return triangle[row][col];
        int x = fun(row - 1, col, triangle);
        int y = fun(row - 1, col - 1, triangle);
        return triangle[row][col] + min(x,y);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1) return triangle[0][0];
        int ans = 1e9;
        for(int i = 0; i < n; i++)
        {
            int x = fun(n-2, i, triangle);
            int y = fun(n-2, i - 1, triangle);
            ans = min(ans, triangle[n-1][i] + min(x,y));
        }
        return ans;
    }
};

/*Memoization-> Adding a 2-D dp to memoize the solution 

TC-> O(N*N)
SC-> O(N*N)-> DP ARRAY & O(N)-> RECURSION STACK SPACE*/

class Solution {
public:
    int fun(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(col > row || row < 0 || col < 0) return 1e9;
        if(dp[row][col] != -1) return dp[row][col];
        if(row == 0) return dp[row][col] = triangle[row][col];
        int x = fun(row - 1, col, triangle, dp);
        int y = fun(row - 1, col - 1, triangle, dp);
        return dp[row][col] = triangle[row][col] + min(x,y);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1) return triangle[0][0];
        vector<vector<int>>dp(n, vector<int>(n,-1));
        int ans = 1e9;
        for(int i = 0; i < n; i++)
        {
            int x = fun(n-2, i, triangle, dp);
            int y = fun(n-2, i - 1, triangle, dp);
            ans = min(ans, triangle[n-1][i] + min(x,y));
        }
        return ans;
    }
};

/*Tabulation->
TC-> O(N*N)
SC -> O(N*N) */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1) return triangle[0][0];
        vector<vector<int>>dp(n, vector<int>(n));

        dp[0][0] = triangle[0][0];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <=i; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = triangle[0][0];
                    continue;
                }

                int x = 1e9;
                if(i-1 >= 0 && j <= i-1) x = dp[i-1][j];
                int y = 1e9;
                if(i-1>= 0 && j-1 >=0 && j-1 <= i-1) y = dp[i-1][j-1];

                dp[i][j] = triangle[i][j] + min(x,y);

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

/*Space Optimization->
TC-> O(N*N)
SC-> O(2*N)*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1) return triangle[0][0];
        vector<int>prev(n);
        prev[0] = triangle[0][0];

        for(int i = 0; i < n; i++)
        {
            vector<int>temp(n);
            for(int j = 0; j <=i; j++)
            {
                if(i == 0 && j == 0)
                {
                    temp[j] = triangle[0][0];
                    continue;
                }

                int x = 1e9;
                if(i-1 >= 0 && j <= i-1) x = prev[j];
                int y = 1e9;
                if(i-1>= 0 && j-1 >=0 && j-1 <= i-1) y = prev[j-1];

                temp[j] = triangle[i][j] + min(x,y);

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