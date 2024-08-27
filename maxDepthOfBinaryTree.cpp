/*TC -> O(n)
  SC -> O(n)
  */
class Solution {
public:
    int fun(TreeNode* root)
    {
        if(root == NULL) return 0;
        int lh = 1 + fun(root->left);
        int rh = 1 + fun(root->right);
        return max(lh, rh);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return fun(root);
    }
};
