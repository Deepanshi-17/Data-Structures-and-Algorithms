/*TC -> O(V) + O(V + E)
  SC -> O(V) + O(V) + O(V)
*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node, vector<bool>& visited, vector<int> adj[], stack<int>& st)
	{
	    visited[node] = true;
	    for(auto it: adj[node])
	    {
	        if(!visited[it])
	        dfs(it, visited, adj, st);
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>v;
	    vector<bool>visited(V,false);
	    stack<int>st;
	    for(int i = 0; i < V; i++)
	    {
	        if(!visited[i])
	        dfs(i, visited, adj, st);
	    }
	    while(!st.empty())
	    {
	        v.push_back(st.top());
	        st.pop();
	    }
	    return v;
	}
};
