/* TC-> O(E log V)
  SC -> O(V) + O(V) + O(V + E)*/


class Solution {
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long>dist(n,1e15);
        vector<int>ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>q;
        q.push({0,0}); //dist, node;
        while(!q.empty())
        {
            int node = q.top().second;
            long long distt = q.top().first;
            // if (node == n - 1) break;
            q.pop();
            for(auto it: adj[node])
            {
                int no = it.first;
                long long d = it.second;
                if(dist[no] > distt + d)
                {
                    dist[no] = distt + d;
                    ways[no] = ways[node];
                    q.push({dist[no],no});
                }
                else if(dist[no] == distt + d)
                {
                    ways[no] = (ways[no] + ways[node])%mod;
                }
            }

        }
        return ways[n-1];
    }
};
