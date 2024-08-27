/*TC -> O(n)
  SC -> O(n)
  */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        while(true)
        {
            if(root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                if(st.empty()) break;
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root = root->right;

            }
        }
        return ans;
    }
};
