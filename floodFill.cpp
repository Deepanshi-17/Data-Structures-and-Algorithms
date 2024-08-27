/*TC -> O(n * m * 4)
  SC -> O(n * m) -> queue
  */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int original = image[sr][sc];
        if(original == color) return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;
        vector<pair<int,int>>dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;

            for(auto[dr, dc]: dir)
            {
                int nrow = row + dr;
                int ncol = col + dc;
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == original)
                {
                    q.push({nrow,ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
        return image;
    }
};
