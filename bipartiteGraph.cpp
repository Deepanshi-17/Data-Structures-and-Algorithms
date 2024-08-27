/*TC -> O(V) + O(V + 2E)
  SC -> O(V) + O(V)
  */

class Solution {
public:
    bool dfs(int node, int clr, vector<int>& visited, vector<vector<int>>& graph)
    {
        visited[node] = clr;
        for(auto it: graph[node])
        {
            if(visited[it] == -1){
            if(dfs(it, !clr, visited, graph) == false) return false;}
            else if(visited[it] == clr){
            return false;}
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,-1);
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == -1)
            {
                if(dfs(i, 0, visited, graph) == false) return false;
            }
        }
        return true;
    }
};
