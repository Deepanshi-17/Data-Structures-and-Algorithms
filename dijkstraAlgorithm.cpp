/*TC -> O(ElogV)
  SC -> O(V) + O(V) + O(V)*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V, 1e9);
        dist[S] = 0;
        set<pair<int,int>>st;
        st.insert({0, S});
        while(!st.empty())
        {
            auto it = *(st.begin());
            st.erase(it);
            int dis = it.first;
            int no = it.second;
            
            for(auto i: adj[no])
            {
                int nod = i[0];
                int diss = i[1];
                if(dist[nod] > dist[no] + diss)
                {
                    if(dist[nod] != 1e9)
                    {
                      st.erase({dist[nod], nod});
                    }
                    dist[nod] = dist[no] + diss;
                    st.insert({dist[nod], nod});
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
