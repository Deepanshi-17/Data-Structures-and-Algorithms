/*O(V + E) -> TC
  O(V + E) -> SC*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        vector<int>ans;
        for(int i = 0; i < n; i++)
        {
            for(int u: graph[i]){
            adj[u].push_back(i);
            indegree[i]++;}
        }
        queue<int>q;
        for(int i =0; i < n; i++)
        {
            if(indegree[i] == 0)
            q.push(i);
        }
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto it: adj[x])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
