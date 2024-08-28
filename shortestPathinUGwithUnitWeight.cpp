/*TC -> O(N * 2E) + O(N)
  SC -> O(2E) -> ADJACENCY LIST + O(N) -> QUEUE + O(N) -> DIST ARRAY
  */
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       vector<vector<int>>adj(N+1);
       for(int i = 0; i < edges.size(); i++)
       {
           int u = edges[i][0];
           int v = edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       vector<int>dist(N,1e9);
       dist[src] = 0;
       queue<pair<int,int>>q;
       q.push({src,0});
       while(!q.empty())
       {
           auto i = q.front();
           q.pop();
           int nod = i.first;
           int dis = i.second;
           
           for(auto it: adj[nod])
           {
               if(dist[it] > dist[nod] + 1)
               {
                   dist[it] = dist[nod] + 1;
                   q.push({it, dist[it]});
               }
           }
       }
       for(int i = 0; i < N; i++)
       {
           if(dist[i] == 1e9)
           dist[i] = -1;
       }
       return dist;
    }
};
