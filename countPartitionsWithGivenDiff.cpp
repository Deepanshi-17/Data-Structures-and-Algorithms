/*Recursion
TC -> O(2 ^ n)
SC -> O(n)*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    int fun(int index, vector<int>& arr, int sum)
    {
        if(index == 0)
        {
            if(sum == 0 && arr[0] == 0) return 2;
            if(sum == 0 || arr[0] == sum) return 1;
            return 0;
        }
        int take = 0;
        if(arr[index] <= sum)
        take = fun(index - 1, arr, sum - arr[index]);
        int not_take = fun(index - 1, arr, sum);
        return (take + not_take) % mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        /*
        s1 + s2 = sum
        s1 - s2 = d
        2s1 = sum + d
        s1 = sum + d / 2*/
        
        int sum = 0;
        for(auto it: arr)
        sum += it;
        
        if( sum < d || (sum + d) % 2 != 0) return 0;
        
        int target = (sum + d)/2;
        
        return fun(n-1, arr, target);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*Memoization
TC -> O(n * sum)
SC -> O(n * sum) + O(n)*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    int fun(int index, vector<int>& arr, int sum, vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if(sum == 0 && arr[0] == 0) return dp[index][sum] = 2;
            if(sum == 0 || arr[0] == sum) return dp[index][sum] = 1;
            return dp[index][sum] = 0;
        }
        if(dp[index][sum] != -1) return dp[index][sum];
        int take = 0;
        if(arr[index] <= sum)
        take = fun(index - 1, arr, sum - arr[index], dp);
        int not_take = fun(index - 1, arr, sum, dp);
        return dp[index][sum] = (take + not_take) % mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        /*
        s1 + s2 = sum
        s1 - s2 = d
        2s1 = sum + d
        s1 = sum + d / 2*/
        
        int sum = 0;
        for(auto it: arr)
        sum += it;
        
        if( sum < d || (sum + d) % 2 != 0) return 0;
        
        int target = (sum + d)/2;
        vector<vector<int>>dp(n,vector<int>(target + 1, -1));
        return fun(n-1, arr, target, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*Tabulation
TC -> O(n * sum) + O(n) + O(n)
SC -> O(n* sum)*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    int fun(int n, vector<int>& arr, int sum, vector<vector<int>>& dp)
    {
        for(int i = 0; i < n; i++)
        dp[i][0] = 1;
        
        if(arr[0] <= sum) dp[0][arr[0]] = 1;
        
        if(arr[0] == 0) dp[0][0] = 2;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                int take = 0;
                if(arr[i] <= j)
                take = dp[i-1][j-arr[i]];
                int not_take = dp[i-1][j];
                
                dp[i][j] = (take + not_take) % mod;
            }
        }
        return dp[n-1][sum];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        /*
        s1 + s2 = sum
        s1 - s2 = d
        2s1 = sum + d
        s1 = sum + d / 2*/
        
        int sum = 0;
        for(auto it: arr)
        sum += it;
        
        if( sum < d || (sum + d) % 2 != 0) return 0;
        
        int target = (sum + d)/2;
        vector<vector<int>>dp(n,vector<int>(target + 1, 0));
        return fun(n, arr, target, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends


/*Space Optimization
TC ->  O(n * sum) + O(n) + O(n)
SC -> O(2 * sum)*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    int fun(int n, vector<int>& arr, int sum)
    {
        vector<int>prev(sum + 1, 0);
        vector<int>temp(sum + 1, 0);
        for(int i = 0; i < n; i++)
        prev[0] = 1;
        
        if(arr[0] <= sum) prev[arr[0]] = 1;
        
        if(arr[0] == 0) prev[0] = 2;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                int take = 0;
                if(arr[i] <= j)
                take = prev[j-arr[i]];
                int not_take = prev[j];
                
                temp[j] = (take + not_take) % mod;
            }
            prev = temp;
        }
        return prev[sum];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        /*
        s1 + s2 = sum
        s1 - s2 = d
        2s1 = sum + d
        s1 = sum + d / 2*/
        
        int sum = 0;
        for(auto it: arr)
        sum += it;
        
        if( sum < d || (sum + d) % 2 != 0) return 0;
        
        int target = (sum + d)/2;
        return fun(n, arr, target);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends