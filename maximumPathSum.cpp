/*TC -> O(N)
  SC -> O(H)
  */

class Solution {
public:
    int fun(TreeNode* root, int &maxi)
    {
        if(root == NULL) return 0;
        int lh = max(0, fun(root->left, maxi));
        int rh = max(0, fun(root->right, maxi));
        maxi = max(maxi, lh + rh + root->val);
        return max(lh, rh) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        int maxi = -1e9;
        fun(root, maxi);
        return maxi;
    }
};
