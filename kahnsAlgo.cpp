/*TC -> O(V + E) + O(V) + O(V + E)
  SC -> O(V) + O(V) + O(V)
  */

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int>q;
	    vector<int>indegree(V,0);
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
	    
	    vector<int>ans;
	    
	    while(!q.empty())
	    {
	        auto it = q.front();
	        ans.push_back(it);
	        q.pop();
	        for(auto i: adj[it])
	        {
	            indegree[i]--;
	            if(indegree[i] == 0)
	            q.push(i);
	        }
	    }
	    return ans;
	}
};
