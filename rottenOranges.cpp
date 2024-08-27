/*TC -> O(n * m) + O(n * m * 4)
  SC -> O(n * m) -> queue 

  no visited array required because you are ultimately rotting the fresh orange and hence, they are itself getting marked as visited.
  Use only breadth first search in this scenario. (level wise traversal) , do rememver to maintain the flag.
  */
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0, rot = 0, time = 0;
        queue<pair<int,int>>q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    rot++;
                }
                else if(grid[i][j] == 1)
                fresh++;
            }
        }
        if(fresh == 0 &&  rot == 0) return 0;
        if(rot == 0) return -1;
        if(fresh == 0) return 0;
        
        while(!q.empty())
        {
            int x = q.size();
            bool rott = false;
            while(x--)
            {
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;
                for(int di = -1; di <= +1; di++)
                {
                    for(int dj = -1; dj <= +1; dj++)
                    {
                        int nrow = row + di;
                        int ncol = col + dj;

                        if(abs(di-dj) == 1 && nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 1)
                        {
                            grid[nrow][ncol] = 2;
                            rott = true;
                            q.push({nrow, ncol});
                            fresh--;
                        }
                    }
                }
            }
            if(rott)
            {
                time++;
            }
        }
        return (fresh == 0)? time: -1;
    }
};
