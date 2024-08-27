/*TC -> O(V + 2E) //for undirected graph
  SC -> O(2E) (adjacency list) + O(V) (visited array)  + O(V) (ans array) + O(V) ->Queue 
  */

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int node, vector<int>adj[], int V, vector<bool>& visited, vector<int>& ans)
    {
        queue<int>q;
        q.push(node);
        visited[node] = true;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto it: adj[x])
            {
                if(!visited[it])
                {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>visited(V,false);
        bfs(0, adj, V, visited, ans);
            
        return ans;
    }
};
