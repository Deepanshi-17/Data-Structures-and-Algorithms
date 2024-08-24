/*
Greedy Approach
TC -> O(n log n) + O(n log n) + O(n^2)
SC -> O(1)*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < g.size(); j++)
            {
                if(g[j] <= s[i])
                {
                    count++;
                    g[j] = 1e9;
                    break;
                }
            }
        }
        return count;
    }
};