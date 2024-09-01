/*TC -> O(logN)
  SC -> O(logN)
  */

class Solution {
public:
    TreeNode* fun(TreeNode* root, TreeNode* p,TreeNode* q)
    {
        if(root == NULL) return NULL;
        if(p->val < root->val && q->val < root->val)
        return fun(root->left, p, q);
        if(p->val > root->val && q->val > root->val)
        return fun(root->right, p, q);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fun(root, p, q);
    }
};
