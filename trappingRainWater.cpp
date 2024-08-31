/*TC -> o(n^2)
  SC -> o(1) */
#include <vector>
#include <set>
#include <algorithm>

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
       int n = arr.size();
       set<pair<int, int>> ans;
       
       for(int i = 0; i < n; i++) {
           for(int j = i + 1; j < n; j++) {
               int sum = arr[i] + arr[j];
               if(sum == 0) {
                   int first = min(arr[i], arr[j]);
                   int second = max(arr[i], arr[j]);
                   ans.insert({first, second});
               }
           }
       }
       
       vector<vector<int>> v;
       for (auto &p : ans) {
           v.push_back({p.first, p.second});
       }
       
       return v;
    }
};

/*TC -> O(n + k log k)
  SC -> O(N)*/
class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        unordered_set<int>st;
        set<vector<int>>ans;
        for(int i = 0; i < arr.size(); i++)
        {
            if(st.find(-arr[i]) != st.end())
            {
                int maxi = max(arr[i], -arr[i]);
                int mini = min(arr[i], -arr[i]);
                ans.insert({mini, maxi});
            }
            st.insert(arr[i]);
        }
        vector<vector<int>>v(ans.begin(), ans.end());
        return v;
    }
};
