/*TC -> O(n) + O(m) + O(n * m) + O(n * m * 4)
  SC -> O(n * m) + O(n * m)
  */

class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        visited[row][col] = true;
        for(int di = -1; di <= +1; di++)
        {
            for(int dj = -1; dj <= +1; dj++)
            {
                int nrow = row + di;
                int ncol = col + dj;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && abs(di-dj) == 1 && board[nrow][ncol] == 'O' && !visited[nrow][ncol])
                {
                    dfs(nrow, ncol,visited, board);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O' && !visited[i][0])
            dfs(i,0,visited, board);
            if(board[i][m-1] == 'O' && !visited[i][m-1])
            dfs(i,m-1,visited, board);
        }
        for(int i = 0; i < m; i++)
        {
            if(board[0][i] == 'O' && !visited[0][i])
            dfs(0, i, visited, board);
            if(board[n-1][i] == 'O' && !visited[n-1][i])
            dfs(n-1, i, visited, board);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O' && !visited[i][j])
                board[i][j] = 'X';
            }
        }
    }
};
