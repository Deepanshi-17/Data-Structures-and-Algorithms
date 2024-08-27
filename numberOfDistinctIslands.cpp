/*TC -> O(N * M * log(N * M)
  SC -> O(N) = O(N * M)
  */

#include<bits/stdc++.h>
class Solution {
  public:
    void dfs(int parentrow, int parentcol, int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int,int>>& v)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = true;
        v.push_back({row - parentrow, col - parentcol});
        for(int di = -1; di <= +1; di ++)
        {
            for(int dj = -1; dj <= +1; dj++)
            {
                int nrow = row + di;
                int ncol = col + dj;
                if(abs(di-dj) == 1 && nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    dfs(parentrow, parentcol, nrow, ncol, grid, visited, v);
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    vector<pair<int,int>>v;
                    dfs(i, j, i, j, grid, visited, v);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};
