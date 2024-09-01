/*TC -> O(N)
  SC -> O(N)
  */

class Solution {
private:
TreeNode* prev;
TreeNode* first;
TreeNode* last;
TreeNode* middle;
public:
    void fun(TreeNode* root)
    {
        if(root == NULL) return;
        fun(root->left);
        if(prev->val > root->val)
        {
            if(first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }

        prev = root;
        fun(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = last = middle = NULL;
        prev = new TreeNode(INT_MIN);
        fun(root);
        if(first && last) 
        swap(first->val, last->val);
        else if(first && middle)
        swap(first->val, middle->val);
    }
};
