/*
USING DFS

TC - O(V) + O(V + 2E)
  SC - O(V + V)
*/

class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        visited[node] = true;
        for(int i = 0; i < n; i++)
        {
            if(isConnected[node][i] == 1 && !visited[i])
            {
                dfs(i, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool>visited(n,false);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i, visited, isConnected);
            }
        }
        return count;
    }
};

/*
USING BFS

TC - O(V) + O(V + 2E)
  SC - O(V + V)
*/

class Solution {
public:
    void bfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        queue<int>q;
        q.push(node);
        visited[node] = true;
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i = 0; i < n; i++)
            {
                if(isConnected[x][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool>visited(n,false);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                bfs(i, visited, isConnected);
            }
        }
        return count;
    }
};
