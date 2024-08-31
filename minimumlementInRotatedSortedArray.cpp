/*TC -> O(log n)
  SC -> O(1) */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high)
        {
            if(nums[low] < nums[high])
            return nums[low];
            if(high == low)
            return nums[low];

            int mid = low + (high - low)/2;
            if(nums[mid] >= nums[low])
            low = mid + 1;
            else
            high = mid;
        }
        return -1;
    }
};
