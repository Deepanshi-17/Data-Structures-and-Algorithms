/*Recursion
TC -> O(2^n)
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
    int fun(int index, int totWeight, int val[], int wtArray[])
    {
        if(totWeight == 0 || index < 0) return 0;
        if(index == 0)
        {
            return (totWeight / wtArray[index]) * val[index];
        }
        int take = -1e9;
        if(wtArray[index] <= totWeight)
        {
            take = val[index] + fun(index, totWeight - wtArray[index], val, wtArray);
        }
        int not_take = fun(index - 1, totWeight, val, wtArray);
        return max(take, not_take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return fun(N-1, W, val, wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends

/*Memoization
TC -> O(n * totWeight)
SC -> O(n * totWeight) -> dp array + O(n)
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int index, int totWeight, int val[], int wtArray[], vector<vector<int>>& dp)
    {
        if(totWeight == 0 || index < 0) return 0;
        if(index == 0)
        {
            return dp[index][totWeight] = (totWeight / wtArray[index]) * val[index];
        }
        if(dp[index][totWeight] != -1) return dp[index][totWeight];
        int take = -1e9;
        if(wtArray[index] <= totWeight)
        {
            take = val[index] + fun(index, totWeight - wtArray[index], val, wtArray, dp);
        }
        int not_take = fun(index - 1, totWeight, val, wtArray, dp);
        return dp[index][totWeight] = max(take, not_take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N, vector<int>(W + 1, -1));
        return fun(N-1, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends

/*Tabulation
TC -> O(n * totWeight)
SC -> O(n * totWeight)

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int n, int totWeight, int val[], int wtArray[], vector<vector<int>>& dp)
    {
        for(int i = 0; i <=totWeight; i++)
        {
            dp[0][i] = (i/wtArray[0]) * val[0];
        }
        for(int i = 0; i < n; i++)
        dp[i][0] = 0;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= totWeight; j++)
            {
                int take = -1e9;
                if(wtArray[i] <= j)
                {
                    take = val[i] + dp[i][j-wtArray[i]];
                }
                int not_take = dp[i-1][j];
                
                dp[i][j] = max(take, not_take);
            }
        }
        return dp[n-1][totWeight];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N, vector<int>(W + 1, 0));
        return fun(N, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends

/*Space Optimization
TC -> O(n * totWeight)
SC -> O(2 * totWeight)
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int n, int totWeight, int val[], int wtArray[])
    {
        vector<int>prev(totWeight + 1, 0);
        for(int i = 0; i <=totWeight; i++)
        {
            prev[i] = (i/wtArray[0]) * val[0];
        }
        for(int i = 0; i < n; i++){
        prev[0] = 0;
        }
        
        for(int i = 1; i < n; i++)
        {
            vector<int>temp(totWeight + 1);
            temp[0] =0;
            for(int j = 1; j <= totWeight; j++)
            {
                int take = -1e9;
                if(wtArray[i] <= j)
                {
                    take = val[i] + temp[j-wtArray[i]];
                }
                int not_take = prev[j];
                
                temp[j] = max(take, not_take);
            }
            prev = temp;
        }
        return prev[totWeight];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return fun(N, W, val, wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends