/*TC -> O(N)
SC -> O(H)*/
class Solution {
public:
    TreeNode* fun(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL || root == q || root == p) return root;
        TreeNode* left_ = fun(root->left, p, q);
        TreeNode* right_ = fun(root->right, p, q);
        if(left_ == NULL)
        return right_;
        else if(right_ == NULL)
        return left_;
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fun(root, p, q);
    }
};
