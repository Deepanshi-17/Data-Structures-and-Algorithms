/*TC -> O(N) visiteting all nodes
  SC -> O(N) -> Stack 
  */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        if(root->left == NULL && root->right == NULL) return {root->val}; 
        vector<int>ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* x = st.top();
            ans.push_back(x->val);
            st.pop();
            if(x->right)
            st.push(x->right);
            if(x->left)
            st.push(x->left);
        }
        return ans;
    }
};
