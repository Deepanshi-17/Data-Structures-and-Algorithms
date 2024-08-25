/*Tabulation
TC -> O(n * m)
SC -> O(n * m)
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int n, int m, string str1, string str2, vector<vector<int>>& dp)
    {
        for(int i = 0; i <=n; i++)
        dp[i][0] = 0;
        for(int j = 0; j <=m; j++)
        dp[0][j] = 0;
        int maxi = 0;
        for(int i = 1; i <=n; i++)
        {
            for(int j = 1; j <=m; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                     dp[i][j] = 1 + dp[i-1][j-1];
                     maxi = max(maxi, dp[i][j]);
                }
                else
                dp[i][j] = 0;
            }
        }
        return maxi;
    }
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        return fun(n, m, str1, str2, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends

/*Space Optimization ->
TC -> O(n * m)
SC -> O(2 * m)
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int n, int m, string str1, string str2)
    {
        vector<int>prev(m+1);
        for(int i = 0; i <=n; i++)
        prev[0] = 0;
        for(int j = 0; j <=m; j++)
        prev[j] = 0;
        int maxi = 0;
        for(int i = 1; i <=n; i++)
        {
            vector<int>temp(m+1);
            temp[0] = 0;
            for(int j = 1; j <=m; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                     temp[j] = 1 + prev[j-1];
                     maxi = max(maxi, temp[j]);
                }
                else
                temp[j] = 0;
            }
            prev = temp;
        }
        return maxi;
    }
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        return fun(n, m, str1, str2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends