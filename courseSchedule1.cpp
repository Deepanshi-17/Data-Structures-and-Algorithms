/*TC -> O(V + E)
  SC -> O(V + E) + O(V) + O(V)
  */

class Solution {
public:
    bool dfs(int node, vector<bool>& visited, vector<bool>& pathvis, vector<vector<int>>& adj)
    {
        visited[node] = true;
        pathvis[node] = true;

        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                if(dfs(it, visited, pathvis, adj)) return false;
            }
            else if(pathvis[it]) return false;
        }
        pathvis[node] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<bool>visited(numCourses,false);
        vector<bool>pathvis(numCourses,false);

        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i])
            {
                if(dfs(i,visited, pathvis, adj)) return false;
            }
        }
        return true;
    }
};
