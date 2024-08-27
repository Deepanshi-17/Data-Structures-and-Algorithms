/*TC -> O(V) + O(V + 2E)
  SC -> O(V) -> queue + O(V) -> visited array*/
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node, vector<bool>& visited, vector<int>adj[])
    {
        queue<pair<int,int>>q;
        q.push({-1,node});
        visited[node] = true;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int parent = it.first;
            int nod = it.second;
            for(auto i: adj[nod])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push({nod,i});
                }
                else if(i != parent) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(bfs(i, visited, adj)) return true;
            }
        }
        return false;
    }
};
