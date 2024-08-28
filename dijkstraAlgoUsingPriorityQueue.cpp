/*TC ->  O(ElogV)
  SC -> O(E + V) 
  */
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V, 1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        dist[S] = 0;
        q.push({0,S});
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int node = it.second;
            int dis = it.first;
            
            for(auto i: adj[node])
            {
                int nod = i[0];
                int diss = i[1];
                
                if(dist[nod] > dist[node] + diss)
                {
                    dist[nod] = dist[node] + diss;
                    q.push({dist[nod], nod});
                }
            }
        }
        for(int i = 0; i < V; i++)
        {
            if(dist[i] == 1e9)
            dist[i] = -1;
        }
        return dist;
    }
};
