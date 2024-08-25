/*Recursion
TC -> O(2 ^ n)
SC -> O(n)
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int fun(int index, int price[], int n)
    {
        if(n == 0 || index < 0) return 0;
        if(index == 0)
        {
            return (n / (index + 1)) * price[index];
        }
        int take = -1e9;
        if(n >= index + 1)
        {
            take = price[index] + fun(index, price, n - (index + 1));
        }
        int not_take = fun(index - 1, price, n);
        return max(take, not_take);
    }
    int cutRod(int price[], int n) {
        return fun(n-1, price, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends 

/*Memoization 
TC ->  O(n * n)
SC -> O(n * n) + O(n)
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int fun(int index, int price[], int n, vector<vector<int>>& dp)
    {
        if(n == 0 || index < 0) return 0;
        if(index == 0)
        {
            return dp[index][n] = (n / (index + 1)) * price[index];
        }
        if(dp[index][n] != -1) return dp[index][n];
        int take = -1e9;
        if(n >= index + 1)
        {
            take = price[index] + fun(index, price, n - (index + 1), dp);
        }
        int not_take = fun(index - 1, price, n, dp);
        return dp[index][n] = max(take, not_take);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1, -1));
        return fun(n-1, price, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*Tabulation
TC -> O(n * n)
SC -> O(n * n)
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int fun(int n, int price[], int length, vector<vector<int>>& dp)
    {
        for(int i = 0; i < n; i++)
        dp[i][0] = 0;
        
        
        for(int i = 0; i <= length; i++)
        dp[0][i] = (i/1 * price[0]);
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <=length; j++)
            {
                int take = -1e9;
                if(j >= i + 1)
                take = price[i] + dp[i][j-(i+1)];
                int not_take = dp[i-1][j];
                
                dp[i][j] = max(take, not_take);
            }
        }
        return dp[n-1][length];
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1));
        return fun(n, price, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*Space Optimization
TC -> O(n * n)
SC -> O(2 * n)
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int fun(int n, int price[], int length)
    {
        vector<int>prev(length + 1);
        for(int i = 0; i < n; i++)
        prev[0] = 0;
        
        
        for(int i = 0; i <= length; i++)
        prev[i] = (i/1 * price[0]);
        
        for(int i = 1; i < n; i++)
        {
            vector<int>temp(length + 1);
            temp[0] = 0;
            for(int j = 1; j <=length; j++)
            {
                int take = -1e9;
                if(j >= i + 1)
                take = price[i] + temp[j-(i+1)];
                int not_take = prev[j];
                
                temp[j] = max(take, not_take);
            }
            prev = temp;
        }
        return prev[length];
    }
    int cutRod(int price[], int n) {
        return fun(n, price, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends