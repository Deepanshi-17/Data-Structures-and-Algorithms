/*TC -> O(n)
  SC -> O(H) */

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
    TreeNode* fun(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans)
    {
        if(root == NULL) return NULL;
        root->left = fun(root->left, st, ans);
        root->right = fun(root->right, st, ans);

        if(st.find(root->val) != st.end())
        {
            if(root->left)
            ans.push_back(root->left);
            if(root->right)
            ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>st;
        for(auto it: to_delete)
        st.insert(it);
        fun(root, st, ans);
        if(st.find(root->val) == st.end())
        {
            ans.push_back(root);
        }
        return ans;
    }
};
