/*TC -> O(V ^ 3)
  SC -> O(V) */
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,1e9));
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            mat[u][v] = w;
            mat[v][u] = w;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) mat[i][j] = 0;
            }
        }
        for(int k = 0; k < n; k++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int i = 0; i < n; i++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        int city = -1;
        int maxcount = 1e9;

        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] <= distanceThreshold)
                count++;
            }

            if(count <= maxcount)
            {
                maxcount = count;
                city = max(city, i);
            }
        }
        return city;
    }
};
