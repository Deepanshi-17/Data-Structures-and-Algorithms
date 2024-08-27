/*TC -> O(N)
  SC -> O(2 * N)
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        if(root == NULL) return {};
        if(root->left == NULL && root->right == NULL) return {root->val};
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* x = st1.top();
            st1.pop();
            st2.push(x);
            if(x->left)
            st1.push(x->left);
            if(x->right)
            st1.push(x->right);
        }
        vector<int>ans;
        while(!st2.empty())
        {
            auto it = st2.top();
            st2.pop();
            ans.push_back(it->val);
        }
        return ans;
    }
};
