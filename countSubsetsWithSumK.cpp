/*Recursion
TC -> O(2 ^n)
SC -> O(n)
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int fun(int index, int arr[], int sum)
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
	    return take + not_take;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    return fun(n-1, arr, sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends

/*Memoization
TC -> O(n * sum)
SC -> O(n) + O(n * sum)
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 1e9 + 7;
	public:
	int fun(int index, int arr[], int sum, vector<vector<int>>& dp)
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
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum + 1, -1));
	    return fun(n-1, arr, sum, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends

/*Tabulation ->
TC -> O(n * sum)
SC -> O(n * sum)*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 1e9 + 7;
	public:
	int fun(int n, int arr[], int sum, vector<vector<int>>& dp)
	{
	    
	    for(int i = 0; i < n; i++)
	    {
	        dp[i][0] = 1;
	    }
	    if(arr[0] <= sum)
	    dp[0][arr[0]] = 1;
	    
	    if(arr[0] == 0)
	    dp[0][0] = 2;
	    
	    for(int i = 1; i < n; i++)
	    {
	        for(int j = 0; j <= sum; j++)
	        {
	            int take = 0;
	            if(arr[i] <= j)
	            take = dp[i-1][j-arr[i]];
	            int not_take = dp[i-1][j];
	            
	            dp[i][j] = (take + not_take)%mod;
	        }
	    }
	    return dp[n-1][sum];
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum + 1, 0));
	    return fun(n, arr, sum, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends

/*Space Optimization
TC -> O(n * sum)
SC -> O(2 * sum)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 1e9 + 7;
	public:
	int fun(int n, int arr[], int sum)
	{
	    
	    vector<int>prev(sum + 1, 0);
	    for(int i = 0; i < n; i++)
	    {
	        prev[0] = 1;
	    }
	    if(arr[0] <= sum)
	    prev[arr[0]] = 1;
	    
	    if(arr[0] == 0)
	    prev[0] = 2;
	    
	    for(int i = 1; i < n; i++)
	    {
	        vector<int>temp(sum + 1, 0);
	        for(int j = 0; j <= sum; j++)
	        {
	            int take = 0;
	            if(arr[i] <= j)
	            take = prev[j-arr[i]];
	            int not_take = prev[j];
	            
	            temp[j] = (take + not_take)%mod;
	        }
	        prev = temp;
	    }
	    return prev[sum];
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    return fun(n, arr, sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends