/*Recursion
TC -> O(K^N)
SC -> O(N)*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int index, vector<int>& arr, int k)
    {
        int n = arr.size();
        if(index == 0) return 0;
        int mini = 1e9;
        for(int i = 1; i <=k; i++)
        {
            int x = 1e9;
            if(index - i >= 0)
            {
                x = abs(arr[index] - arr[index - i]) + fun(index - i, arr, k);
                mini = min(mini, x);
            }
        }
        return mini;
    }
    int minimizeCost(vector<int>& arr, int& k) {
        int n = arr.size();
        return fun(n-1, arr, k);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends

/*Memoization ->
TC -> O(K * N)
SC -> O(N) + O(N)
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int index, vector<int>& arr, int k, vector<int>& dp)
    {
        int n = arr.size();
        if(index == 0) return 0;
        if(dp[index] != -1) return dp[index];
        int mini = 1e9;
        for(int i = 1; i <=k; i++)
        {
            int x = 1e9;
            if(index - i >= 0)
            {
                x = abs(arr[index] - arr[index - i]) + fun(index - i, arr, k, dp);
                mini = min(mini, x);
            }
        }
        return dp[index] = mini;
    }
    int minimizeCost(vector<int>& arr, int& k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return fun(n-1, arr, k, dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends

/*Tabulation ->
TC -> O(N * K)
SC ->  O(N)*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& arr, int& k) {
        int n = arr.size();
        vector<int>dp(n);
        dp[0] = 0;
        for(int i = 1; i < n; i++)
        {
            int mini = 1e9;
            for(int j = 1; j <=k; j++)
            {
                int x = 1e9;
                if(i - j >= 0)
                {
                    x = abs(arr[i] - arr[i-j]) + dp[i-j];
                    mini = min(mini, x);
                }
            }
            dp[i] = mini;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends