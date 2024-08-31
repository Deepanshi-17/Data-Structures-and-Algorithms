/*TC -> O(N)
  SC -> O(1)
  */
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == key)
            return i;
        }
        return -1;
    }
};

/*TC -> O(nlogn)
  SC -> O(1) */

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int target = key;
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid] == target) return mid;
            if(arr[low] <= arr[mid])
            {
                if(arr[low] <= target && arr[mid] > target)
                high = mid-1;
                
                else
                low = mid + 1;
            }
            else
            {
                if(arr[mid] < target && target <= arr[high])
                low = mid + 1;
                
                else
                high = mid - 1;
            }
        }
        return -1;
    }
};
