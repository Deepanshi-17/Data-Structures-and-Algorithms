/*TC -> O(V + 2E)
  SC -> O(2E) -> adjacency list + O(V) -> returning answer + O(V) -> recursion stack space + O(V) -> visited array
  */
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> adj[], vector<int>& ans, vector<bool>&visited)
    {
        visited[node] = true;
        ans.push_back(node);
        for(auto it: adj[node])
        {
            if(!visited[it])
            dfs(it, adj, ans, visited);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<bool>visited(V,false);
       vector<int>ans;
       dfs(0, adj, ans, visited);
       return ans;
    }
};
