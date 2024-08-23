/*Recursion
TC -> O(2 ^ n)
SC -> O(n)*/
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool fun(int index, vector<int>& arr, int sum)
    {
        if(sum == 0) return true;
        if(index == 0)
        {
            if(sum == arr[0]) return true;
            return false;
        }
        
        bool take = false;
        if(arr[index] <= sum)
        take = fun(index - 1, arr, sum - arr[index]);
        bool not_take = fun(index - 1, arr, sum);
        return take || not_take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return fun(n-1, arr, sum);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
/*Memoization 
TC -> O(n * sum)
SC ->nO(n * sum) + O(n)*/
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool fun(int index, vector<int>& arr, int sum, vector<vector<int>>& dp)
    {
        if(sum == 0) return true;
        if(index == 0)
        {
            if(sum == arr[0]) return true;
            return false;
        }
        if(dp[index][sum] != -1) return dp[index][sum];
        bool take = false;
        if(arr[index] <= sum)
        take = fun(index - 1, arr, sum - arr[index], dp);
        bool not_take = fun(index - 1, arr, sum, dp);
        return dp[index][sum] = take || not_take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum + 1, -1));
        return fun(n-1, arr, sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends

/*Tabulation
TC -> O(n * sum)
SC ->O(n * sum)*/
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool fun(int index, vector<int>& arr, int sum, vector<vector<int>>& dp)
    {
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        if(arr[0] <= sum)
        dp[0][arr[0]] = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                int take = 0;
                if(arr[i] <= j)
                take = dp[i-1][j-arr[i]];
                int not_take = dp[i-1][j];
                
                dp[i][j] = take || not_take;
            }
        }
        return dp[n-1][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum + 1, 0));
        return fun(n-1, arr, sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
/*Space Optimization
TC -> O(n * sum)
SC -> O(sum)*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool fun(int index, vector<int>& arr, int sum)
    {
        vector<int>prev(sum + 1, 0);
        vector<int>temp(sum + 1, 0);
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            prev[0] = 1;
            temp[0] = 1;
        }
        if(arr[0] <= sum)
        {prev[arr[0]] = 1;
        temp[arr[0]] = 1;}
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                int take = 0;
                if(arr[i] <= j)
                take = prev[j-arr[i]];
                int not_take = prev[j];
                
                temp[j] = take || not_take;
            }
            prev = temp;
        }
        return prev[sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return fun(n-1, arr, sum);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends