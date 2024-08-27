/*
BRUTE FORCE APPROACH
TC -> O(N * N)
  SC -> O(H) //RECURSIVE STACK SPACE
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL ||(root->left == NULL && root->right == NULL)) return true;
        int lh = fun(root->left);
        int rh = fun(root->right);
        if(abs(lh - rh) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

/*TC -> O(N)
  SC -> O(H) //RECURSIVE STACK SPACE
  */
class Solution {
public:
    int fun(TreeNode* root)
    {
        if(root == NULL) return true;
        int lh = fun(root->left);
        if(lh == -1) return -1;
        int rh = fun(root->right);
        if(rh == -1) return -1;
        int y = abs(lh-rh);
        if(y > 1) return -1;
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return true;
        return fun(root) == -1? false: true;
    }
};
