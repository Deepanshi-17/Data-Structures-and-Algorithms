/*Tabulation Method
TC -> O(n * m) + O(max(n,m))
SC -> O(n * m)
*/

class Solution {
  public:
    string fun(int n, int m, string s, string t, vector<vector<int>>& dp)
    {
        for(int i = 0; i <=n; i++)
        dp[i][0] = 0;
        for(int j = 0; j <=m; j++)
        dp[0][j] = 0;
        
        for(int i = 1; i <=n; i++)
        {
            for(int j = 1; j <=m; j++)
            {
                if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
                
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        string ans = "";
        int i = n;
        int j = m;
        while( i > 0 && j > 0)
        {
            if(s[i-1] == t[j-1])
            {
                ans += s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] >= dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        return fun(n, m, s, t, dp);
    }
};