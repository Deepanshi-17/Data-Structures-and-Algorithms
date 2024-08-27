/*TC-> O(N)
  SC -> O(N) + O(N)
  */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int x = q.size();
            vector<int>v;
            while(x--)
            {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);   
            }
            ans.push_back(v);
        }
        return ans;
    }
};
