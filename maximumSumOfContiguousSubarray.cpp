/*TC -> O(n^3)
SC -> O(1)*/

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        long long maxi = -1e9;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                long long sum = 0;
                for(int k = i; k <=j; k++)
                {
                    sum += arr[k];
                    maxi = max(maxi, sum);
                }
            }
        }
        return maxi;
    }
};

/*TC -> O(n^2)
SC -> O(1)*/
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        long long maxi = -1e9;
        for(int i = 0; i < n; i++)
        {
            long long sum = 0;
            for(int j = i; j < n; j++)
            {
                sum += arr[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};

/*TC -> O(N)
  SC -> O(1)
  */
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        long long maxi = -1e9;
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            maxi = max(maxi, sum);
            if(sum < 0)
            sum = 0;
        }
        return maxi;
    }
};
