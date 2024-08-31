/*TC -> O(N)
  SC -> O(H)
  */
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int fun(Node* root, int& diameter)
    {
        if(root == NULL) return 0;
        int lh = fun(root->left, diameter);
        int rh = fun(root->right, diameter);
        diameter = max(diameter, lh + rh + 1);
        return 1 + max(lh, rh);
    }
    int diameter(Node* root) {
        int diameter = 0;
        fun(root, diameter);
        return diameter;
    }
};
