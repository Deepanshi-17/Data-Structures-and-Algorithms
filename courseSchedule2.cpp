/*TC -> O(V + E)
  SC ->  O(V + E) + O(V) + O(V)*/

class Solution {
public:
	vector<int> topoSort(int V, vector<vector<int>>& adj) 
	{
	    vector<int>ans;
	    vector<int>indegree(V,0);
	    for(int i = 0; i < V; i++)
	    {
	        for(auto it: adj[i])
	        indegree[it]++;
	    }
	    queue<int>q;
	    for(int i = 0; i < V; i++)
	    {
	        if(indegree[i] == 0)
	        q.push(i);
	    }
	    while(!q.empty())
	    {
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto it: adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	            q.push(it);
	        }
	    }
	    return ans;
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int>ans = topoSort(numCourses, adj);
        if(ans.size() == numCourses) return ans;
        return {};
    }
};
