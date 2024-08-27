/*TC -> o(n * m * 4)
  SC -> O(n * m) + O(n * m)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>>dir = {{-1,0},{+1,0}, {0,-1}, {0,1}};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for(auto[dr,dc]: dir)
            {
                int nrow = row + dr;
                int ncol = col + dc;
                if(nrow >=0 && nrow < n && ncol>=0 && ncol < m && mat[nrow][ncol] == 1 && !visited[nrow][ncol])
                {
                    mat[nrow][ncol] = mat[row][col] + 1;
                    visited[nrow][ncol] = true;
                    q.push({nrow,ncol});
                }
            }
        }
        return mat;
    }
};
