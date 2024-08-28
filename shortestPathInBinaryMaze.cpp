/*TC -> O(n * n * 4 * 4)
  SC -> O(n * n) 
  */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[n-1][n-1] == 1 || grid[0][0] == 1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;

        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int di = -1; di <= +1; di++)
            {
                for(int dj = -1; dj <= +1; dj++)
                {
                    int nrow = row + di;
                    int ncol = col + dj;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && dist[nrow][ncol] > dist[row][col] + 1)
                    {
                        dist[nrow][ncol] = dist[row][col] + 1;
                        q.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n-1][n-1] == 1e9? -1: dist[n-1][n-1];
    }
};
