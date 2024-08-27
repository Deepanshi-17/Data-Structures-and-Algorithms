/*TC -> o(n)
  SC -> o(n) ->recursive stack space
  */

class Solution {
public:
    int fun(int &maxi, TreeNode* root)
    {
        if(root == NULL) return 0;
        int lh = fun(maxi, root->left);
        int rh = fun(maxi, root->right);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 0;
        int maxi = 0;
        fun(maxi, root);
        return maxi;
    }
};
