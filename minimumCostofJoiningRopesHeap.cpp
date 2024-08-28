/*TC -> O(n log n)
SC -> O(n) */

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        long long cost = 0;
        priority_queue<long long,vector<long long>,greater<long long>>q;
        for(int i = 0; i < arr.size(); i++)
        q.push(arr[i]);
        while(q.size() != 1)
        {
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
            long long sum = x + y;
            q.push(sum);
        }
        return q.top();
    }
};
