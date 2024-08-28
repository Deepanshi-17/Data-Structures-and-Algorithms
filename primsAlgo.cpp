/*TC -> O(ElogE)
  SC -> O(E + V)
  */

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>visited(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        int sum = 0;
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int dis = it.first;
            int node = it.second;
            if(visited[node])
            continue;
            sum += dis;
            visited[node] = true;
            for(auto it: adj[node])
            {
                int no = it[0];
                int di = it[1];
                q.push({di, no});
                
            }
        }
        return sum;
    }
};
