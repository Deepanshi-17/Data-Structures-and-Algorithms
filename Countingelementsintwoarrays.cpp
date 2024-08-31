/*TC -> O(NlogN)+ O(MlogN)
  SC -> O(N)*/

class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        vector<int>ans;
        sort(arr2, arr2 + n);
        for(int i = 0; i < m; i++)
        {
            int low = 0;
            int high = n-1;
            while(low <= high)
            {
                //if(low == high) ans.push_back(low);
                int mid = low + (high - low)/2;
                if(arr2[mid] <= arr1[i])
                {
                    low = mid + 1;
                }
                else
                high = mid - 1;
            }
           ans.push_back(low);
        }
        return ans;
    }
};
