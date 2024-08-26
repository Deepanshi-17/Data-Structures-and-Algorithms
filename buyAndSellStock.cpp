#include<bits/stdc++.h>
using namespace std;
#include<vector>
/*Brute Force Approach ->
TC -> O(n^2)
SC -> O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            for(int j = i + 1; j < prices.size(); j++)
            {
                maxi = max(maxi , prices[j] - prices[i]);
            }
        }
        return maxi;
    }
};

/*Optimal Approach
TC -> O(n)
SC -> O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > mini)
            maxi = max(maxi, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return maxi;
    }
};
