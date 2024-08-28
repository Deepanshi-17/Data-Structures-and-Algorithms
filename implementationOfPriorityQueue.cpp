/*TC -> O(logn)
  SC -> O(1) */

class Solution {
  public:
    int extractMax() {
        int res = H[0]; //root stores the max element
        H[0] = H[s--]; //last elment is leaf node, that's why bring it to the top and decrease the heap size. s-- removes element from the last of the heap. leaf node removed.
        shiftDown(0); //the first element should come at the appropriate position. As it is small it will come at down.
        return res;
    }
};
