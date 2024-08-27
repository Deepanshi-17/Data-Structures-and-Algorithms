/*TC -> O(N)
  SC -> O(N)
  */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        stack<TreeNode*>st;
        while(!st.empty() || root!= NULL)
        {
            if(root!= NULL)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                TreeNode* temp = st.top()->right;
                if(temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && st.top()->right == temp)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    root = temp;
                }
            }
        }
        return ans;
    }
};
