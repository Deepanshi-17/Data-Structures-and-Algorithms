/*Recursion
TC - O(2^N)
SC - o(N)
 */

class Solution {
  public:
    int fun(int index, vector<int>& height, int n)
    {
        if(index == 0)
        return 0;
        if(index == 1) return abs(height[0] - height[1]);
        int x = 1e9;
        if(index - 1 >= 0) 
        x = abs(height[index - 1] - height[index]) + fun(index - 1, height, n);
        int y = 1e9;
        if(index - 2 >=0 )
        y = abs(height[index - 2] - height[index]) + fun(index - 2, height, n);
        return min(x,y);
    }
    int minimumEnergy(vector<int>& height, int n) {
        return fun(n-1, height, n);
    }
};

/*Memoization
TC -> O(N)
SC -> O(N)-> recursion stack space + O(N) -> dp array*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int index, vector<int>& height, int n, vector<int>& dp)
    {
        if(index == 0)
        return 0;
        if(dp[index] != -1) return dp[index];
        int x = 1e9;
        if(index - 1 >= 0) 
        x = abs(height[index - 1] - height[index]) + fun(index - 1, height, n, dp);
        int y = 1e9;
        if(index - 2 >=0 )
        y = abs(height[index - 2] - height[index]) + fun(index - 2, height, n, dp);
        return dp[index] =  min(x,y);
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n,-1);
        return fun(n-1, height, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*Tabulation->
TC -> O(N)
SC -> O(N) -> dp array */
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        for(int i = 2; i < n; i++)
        {
            int x = 1e9;
            if(i - 1 >= 0)
            x = abs(height[i] - height[i-1]) + dp[i-1];
            int y = 1e9;
            if(i - 2 >= 0)
            y = abs(height[i] - height[i-2]) + dp[i-2];
            dp[i] = min(x,y);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*Space Optimization
TC -> O(N)
SC -> O(1)*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        if(n == 1) return 0;
        int prev2 = 0;
        int prev = abs(height[1] - height[0]);
        for(int i = 2; i < n; i++)
        {
            int x = 1e9;
            if(i - 1 >= 0)
            x = abs(height[i] - height[i-1]) + prev;
            int y = 1e9;
            if(i - 2 >= 0)
            y = abs(height[i] - height[i-2]) + prev2;
            int curr = min(x,y);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends