/*TC -> O(V) + O(V) + O(V + E)
SC -> O(V) + O(V) + O(V)
*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>indegree(V,0);
        queue<int>q;
        for(int i = 0; i < V; i++)
        {
            for(int u: adj[i])
            indegree[u]++;
        }
        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            q.push(i);
        }
        while(!q.empty())
        {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(auto i: adj[x])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                q.push(i);
            }
        }
        if(ans.size() == V) return false;
        return true;
    }
};
