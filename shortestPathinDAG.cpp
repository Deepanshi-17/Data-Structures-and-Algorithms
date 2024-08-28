/*TC -> O(N + E)
  SC -> O(N) + O(N + E) + O(N)*/

class Solution {
  public:
     void dfs(int node, vector<bool>& visited, stack<int>& st, vector<vector<pair<int,int>>>& adj)
     {
         visited[node] = true;
         
         for(auto it: adj[node])
         {
             int no = it.first;
             if(!visited[no])
             {
                 dfs(no, visited, st, adj);
             }
         }
         st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>adj(N);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
        }
        
        vector<bool>visited(N,false);
        stack<int>st;
        dfs(0, visited, st, adj);
        
        vector<int>dist(N, 1e9);
        dist[0] = 0;
        while(!st.empty())
        {
            int x = st.top();
            st.pop();
            
            for(auto it: adj[x])
            {
                int no = it.first;
                int dis = it.second;
                if(dist[no] > dist[x] + dis)
                {
                    dist[no] = dist[x] + dis;
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
