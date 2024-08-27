/*TC -> O(V) + O(V + 2E)
  SC -> O(V)-> visited array + O(V) -> recursion stack space
  */
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int parent, int node, vector<bool>& visited, vector<int>adj[])
    {
        visited[node] = true;
        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                if(dfs(node, it, visited, adj)) return true;
            }
            else if(it != parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfs(-1, i, visited, adj)) return true;
            }
        }
        return false;
    }
};
