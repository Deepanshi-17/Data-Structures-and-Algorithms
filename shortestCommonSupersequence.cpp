/*Tabulation Method ->
TC -> O(n * m)
SC -> O(n * m)
*/
class Solution {
public:
    string fun(int n, int m, string text1, string text2, vector<vector<int>>& dp)
    {
        for(int i = 0; i <=n; i++)
        dp[i][0] = 0;
        for(int j = 0; j <=m; j++)
        dp[0][j] = 0;
        
        for(int i = 1; i <=n; i++)
        {
            for(int j = 1; j <=m; j++)
            {
                if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        string ans = "";
        int i = n;
        int j = m;
        while( i > 0 && j > 0)
        {
            if(text1[i-1] == text2[j-1])
            {
                ans += text1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] >= dp[i][j-1])
            {
                ans += text1[i-1];
                i--;
            }
            else
            {
                ans += text2[j-1];
                j--;
            }

        }

        while(i > 0)
        {
            ans += text1[i-1];
            i--;
        }

        while(j > 0)
        {
            ans += text2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1));
        return fun(n, m, str1, str2, dp);
    }
};