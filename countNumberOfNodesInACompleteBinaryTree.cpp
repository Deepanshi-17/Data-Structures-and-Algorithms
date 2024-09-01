/*TC -> O(logN) * O(logN)
SC -> O(H)
  */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rightheight(TreeNode* root)
    {
        int rh = 0;
        if(root == NULL) return rh;
        while(root)
        {
            rh++;
            root = root->right;
        }
        return rh;
    }
    int leftheight(TreeNode* root)
    {
        int lh = 0;
        if(root == NULL) return lh;
        while(root)
        {
            lh++;
            root = root->left;
        }
        return lh;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL)
        return 0;
        int lh = leftheight(root);
        int rh = rightheight(root);
        if(lh == rh)
        return (pow(2,lh) - 1);
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
