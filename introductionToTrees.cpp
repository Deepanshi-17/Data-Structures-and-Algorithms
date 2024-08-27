/*TC -> O(1)
 SC -> O(1)
 */
class Solution {
  public:
    int countNodes(int i) {
        return pow(2, i-1);
    }
};
