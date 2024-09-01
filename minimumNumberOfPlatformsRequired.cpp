/*TC -> O(nlogn) + O(nlogn) + o(n)
  SC -> O(1) */

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	int count = 1;
    	int ans = 1;
    	int i = 0, j = 1;
    	while(i < n && j < n)
    	{
    	    if(arr[j] <= dep[i])
    	    {
    	        count++;
    	        j++;
    	    }
    	    else
    	    {
    	        count--;
    	        i++;
    	    }
    	    ans = max(ans,count);
    	}
    	return ans;
    }
};
