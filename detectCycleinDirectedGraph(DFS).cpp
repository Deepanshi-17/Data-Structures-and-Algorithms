/*TC -> O(V) + O(V + E)
  SC -> O(V) + O(V)
  */

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<bool>& visited, vector<bool>& pathvis, vector<int>adj[])
    {
        visited[node] = true;
        pathvis[node] = true;
        
        for(auto it: adj[node])
        {
            if(!visited[it]){
            if(dfs(it, visited, pathvis, adj)) return true;}
            else if(pathvis[it]) return true;
        }
        pathvis[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        vector<bool>pathvis(V,false);
        
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i,visited, pathvis, adj)) return true;
            }
        }
        return false;
    }
};
