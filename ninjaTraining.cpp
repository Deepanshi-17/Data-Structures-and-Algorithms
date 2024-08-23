/*Recursion ->
TC -> O(3 ^ n)
SC -> O(n) -> recursion stack space*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int last, int day, vector<vector<int>>& arr, int n)
    {
        if(day == 0)
        {
            int maxi = -1e9;
            for(int i = 0; i <=2; i++)
            {
                if(i != last)
                maxi = max(maxi, arr[0][i]);
            }
            return maxi;
        }
        
        int m = -1e9;
        for(int i = 0; i <=2; i++)
        {
            if(i != last)
            {
                int x = -1e9;
                if(day - 1 >= 0) x = arr[day][i] + fun(i, day-1, arr, n);
                m = max(m, x);
            }
        }
        return m;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        return fun(3, n-1, arr, n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*Memoization
TC -> O(day * 3)
SC -> O(day * 4) + O(day)*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(int last, int day, vector<vector<int>>& arr, vector<vector<int>>& dp)
    {
        if(day == 0)
        {
            int x = -1e9;
            for(int i = 0; i < 3; i++)
            {
                if(i != last) x = max(x, arr[0][i]);
            }
            return x;
        }
        if(dp[day][last] != -1) return dp[day][last];
        int ans = -1e9;
        for(int i = 0; i < 3; i++)
        {
            if(i != last)
            {
                int x = -1e9;
                if(day - 1 >=0) 
                x = arr[day][i] + fun(i, day-1, arr, dp);
                ans = max(ans, x);
            }
            
        }
        return dp[day][last] = ans;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        
        vector<vector<int>>dp(n, vector<int>(4,-1));
        return fun(3, n-1, arr, dp);
        
        //TC -> O(3^n))
        //SC -> O(N)
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*Tabulation ->
TC -> O(no. of days * 4 * 3)
SC -> O(no.of days * 4) -> dp array*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(vector<vector<int>>& arr, vector<vector<int>>& dp)
    {
        int n = arr.size();
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][1], arr[0][0]);
        dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        for(int day = 1; day < n; day++)
        {
            for(int last = 0; last < 4; last++)
            {
                int ans = -1e9;
                for(int i = 0; i < 3; i++)
                {
                    if(i != last)
                    {
                        int x = -1e9;
                        if(day - 1 >= 0)
                        {
                            x = arr[day][i] + dp[day-1][i];
                            ans = max(ans, x);
                        }
                    }
                    dp[day][last] = ans;
                }
            }
        }
        return dp[n-1][3];
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        
        vector<vector<int>>dp(n, vector<int>(4, 0));
        return fun(arr, dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*Space Optimization
TC -> O(no. of days * 4 * 3)
SC -> O(2 * 4)*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(vector<vector<int>>& arr)
    {
        int n = arr.size();
        vector<int>prev(4);
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][1], arr[0][0]);
        prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        for(int day = 1; day < n; day++)
        {
            vector<int>temp(4);
            for(int last = 0; last < 4; last++)
            {
                int ans = -1e9;
                for(int i = 0; i < 3; i++)
                {
                    if(i != last)
                    {
                        int x = -1e9;
                        if(day - 1 >= 0)
                        {
                            x = arr[day][i] + prev[i];
                            ans = max(ans, x);
                        }
                    }
                    temp[last] = ans;
                }
            }
            prev = temp;
        }
        return prev[3];
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        return fun(arr);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends