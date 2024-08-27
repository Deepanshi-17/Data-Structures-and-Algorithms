/* Given number of vertices, return the number of undirected graphs that can be formed from those vertices. 
int edges = n * (n-1)/2. But since it is undirected graph then edges / 2. Since, every edge can be present or absent. Hence, pow(2, edges)
TC -> O(1)
  SC -> O(1) */

class Solution {
  public:
    long long count(int n) {
        int edges = n * (n-1)/2;
        return pow(2, edges);
    }
};
