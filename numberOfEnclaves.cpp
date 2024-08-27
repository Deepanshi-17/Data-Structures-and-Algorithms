/*
DFS Approach can also be solved using BFS
TC -> O(n) + O(m) + O(n * m) + O(n * m * 4)
SC -> O(n * m) + O(n)
*/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = true;
        for(int di = -1; di <= +1; di++)
        {
            for(int dj = -1; dj <= +1; dj++)
            {
                int nrow = row + di;
                int ncol = col + dj;
                if(abs(di-dj) == 1 && nrow >=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !visited[nrow][ncol])
                {
                    dfs(nrow, ncol, grid, visited);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i = 0; i < n; i++)
        {
            if(grid[i][0] == 1 && !visited[i][0])
            dfs(i,0,grid,visited);
            if(grid[i][m-1] == 1 && !visited[i][m-1])
            dfs(i,m-1,grid,visited);
        }
        for(int i = 0; i < m; i++)
        {
            if(grid[0][i] == 1 && !visited[0][i])
            dfs(0,i,grid,visited);
            if(grid[n-1][i] == 1 && !visited[n-1][i])
            dfs(n-1,i,grid,visited);
        }
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                count++;
            }
        }
        return count;
    }
};
