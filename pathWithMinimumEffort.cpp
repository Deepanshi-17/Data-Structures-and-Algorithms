/*TC -> O(4 * N * M log(N * M))
  SC -> O(N * M)
  */

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == m-1) return dis;

            for(int di = -1; di <= +1; di++)
            {
                for(int dj = -1; dj <= +1; dj++)
                {
                    int nrow = row + di;
                    int ncol = col + dj;
                    if(abs(di-dj) == 1 && nrow >= 0 && ncol >= 0 && nrow < n && ncol < m)
                    {
                        int new_effort = max(dis, abs(heights[row][col] - heights[nrow][ncol]));
                        if(dist[nrow][ncol] > new_effort)
                        {
                            dist[nrow][ncol] = new_effort;
                            q.push({dist[nrow][ncol],{nrow, ncol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
