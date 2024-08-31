/*TC -> O(logn)
  SC -> O(1) */
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        if(n == 0 || n == 1) return n;
        long long low = 1;
        long long high = n;
        long long ans = 0;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(mid == n/mid) return mid;
            else if(mid < n/mid)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            high = mid - 1;
        }
        return ans;
    }
};
