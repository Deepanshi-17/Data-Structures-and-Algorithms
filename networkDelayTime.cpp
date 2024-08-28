/*TC -> O(E log V)
  SC -> O(E + V)
  */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i = 0; i < times.size(); i++)
        {
            int u1 = times[i][0];
            int u2 = times[i][1];
            int wt = times[i][2];
            adj[u1].push_back({u2,wt});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({k,0});
        vector<int>dist(n+1,1e9);
        dist[k] = 0;
        while(!q.empty())
        {
            int node = q.top().first;
            int time = q.top().second;
            q.pop();
            for(auto it: adj[node])
            {
                int no = it.first;
                int d = it.second;
                if(dist[no] > dist[node] + d)
                {
                    dist[no] = dist[node] + d;
                    q.push({no, dist[no]});
                }
            }
        }

        int maxi = INT_MIN;
        for(int i = 1; i < dist.size(); i++)
        {
            if(dist[i] == 1e9)
            return -1;
            else
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};
