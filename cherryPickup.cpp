/*Recursion ->
TC ->  O(9^n)
SC -> O(n)*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int row, int col1, int col2, vector<vector<int>>& grid, int n, int m)
    {
        if(row == n-1)
        {
            if(col1 == col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }
        int ans = -1e9;
        for(int di = -1; di <= +1; di++)
        {
            for(int dj = -1; dj <= +1; dj++)
            {
                int ncol1 = col1 + di;
                int ncol2 = col2 + dj;
                int x = -1e9;
                if(ncol1 >= 0 && ncol1 < m && ncol2 >= 0 && ncol2 < m && row + 1 < n)
                {
                    if(col1 != col2)
                    {
                        x = grid[row][col1] + grid[row][col2] + fun(row + 1, ncol1, ncol2, grid, n, m);
                    }
                    else
                    x = grid[row][col1] + fun(row + 1, ncol1, ncol2, grid, n, m);
                    ans = max(ans, x);
                }
            }
        }
        return ans;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        return fun(0, 0, m-1, grid, n, m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*Memoization
TC -> O(n * m * m * 9)
SC -> O(n) + O(n * m * m)*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int row, int col1, int col2, vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>>& dp)
    {
        if(row == n-1)
        {
            if(col1 == col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        int ans = -1e9;
        for(int di = -1; di <= +1; di++)
        {
            for(int dj = -1; dj <= +1; dj++)
            {
                int ncol1 = col1 + di;
                int ncol2 = col2 + dj;
                int x = -1e9;
                if(ncol1 >= 0 && ncol1 < m && ncol2 >= 0 && ncol2 < m && row + 1 < n)
                {
                    if(col1 != col2)
                    {
                        x = grid[row][col1] + grid[row][col2] + fun(row + 1, ncol1, ncol2, grid, n, m, dp);
                    }
                    else
                    x = grid[row][col1] + fun(row + 1, ncol1, ncol2, grid, n, m, dp);
                    ans = max(ans, x);
                }
            }
        }
        return dp[row][col1][col2] = ans;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return fun(0, 0, m-1, grid, n, m, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*Tabulation
TC -> O(n * m * m * 9)
SC -> O(n * m * m)*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>>& dp)
    {
        for(int j1 = 0; j1 < m; j1++)
        {
            for(int j2 = 0; j2 < m; j2++)
            {
                if(j1 == j2)
                dp[n-1][j1][j2] = grid[n-1][j1];
                else
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            for(int j1 = 0; j1 < m; j1++)
            {
                for(int j2 = 0; j2 < m; j2++)
                {
                    int ans = -1e9;
                    for(int di = -1; di <= +1; di++)
                    {
                        for(int dj = -1; dj <= +1; dj++)
                        {
                            int ncol1 = j1 + di;
                            int ncol2 = j2 + dj;
                            int x = -1e9;
                            if(ncol1 >= 0 && ncol2 >= 0 && ncol1 < m && ncol2 < m && i + 1 < n)
                            {
                                if(j1 != j2)
                                x = grid[i][j1] + grid[i][j2] + dp[i+1][ncol1][ncol2];
                                else
                                x = grid[i][j1] + dp[i+1][ncol1][ncol2];
                                ans = max(ans, x);
                            }
                        }
                    }
                    dp[i][j1][j2] = ans;
                }
            }
        }
        return dp[0][0][m-1];
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        return fun(grid, n, m, dp);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*Space Optimization 
TC -> O(n * m * m * 9)
SC -> O(m * m)
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(vector<vector<int>>& grid, int n, int m)
    {
        vector<vector<int>>prev(m,vector<int>(m,0));
        for(int j1 = 0; j1 < m; j1++)
        {
            for(int j2 = 0; j2 < m; j2++)
            {
                if(j1 == j2)
                prev[j1][j2] = grid[n-1][j1];
                else
                prev[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            vector<vector<int>>temp(m,vector<int>(m,0));
            for(int j1 = 0; j1 < m; j1++)
            {
                for(int j2 = 0; j2 < m; j2++)
                {
                    int ans = -1e9;
                    for(int di = -1; di <= +1; di++)
                    {
                        for(int dj = -1; dj <= +1; dj++)
                        {
                            int ncol1 = j1 + di;
                            int ncol2 = j2 + dj;
                            int x = -1e9;
                            if(ncol1 >= 0 && ncol2 >= 0 && ncol1 < m && ncol2 < m && i + 1 < n)
                            {
                                if(j1 != j2)
                                x = grid[i][j1] + grid[i][j2] + prev[ncol1][ncol2];
                                else
                                x = grid[i][j1] + prev[ncol1][ncol2];
                                ans = max(ans, x);
                            }
                        }
                    }
                    temp[j1][j2] = ans;
                }
            }
            prev = temp;
        }
        return prev[0][m-1];
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        return fun(grid, n, m);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends