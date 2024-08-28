/*TC-> O(ElogV)
  SC -> O(E + V)
  */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,src}}); //stops, dist, node;
        vector<int>dist(n + 1,1e9);
        dist[src] = 0;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int di = it.second.first;
            int node = it.second.second;

            if(stops > k) continue;
            for(auto i: adj[node])
            {
                int no = i.first;
                int dis = i.second;
                if(dist[no] > di + dis)
                {
                    dist[no] = di + dis;
                    q.push({stops + 1, {dist[no], no}});
                }
            }
        }
        return dist[dst] == 1e9? -1: dist[dst];
    }
};
