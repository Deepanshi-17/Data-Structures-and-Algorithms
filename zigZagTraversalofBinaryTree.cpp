/*TC-> O(N)
  SC -> O(H) + O(N)
  */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int x = q.size();
            vector<int>v;
            while(x--)
            {
                TreeNode* y = q.front();
                q.pop();
                v.push_back(y->val);
                if(y->left)
                q.push(y->left);
                if(y->right)
                q.push(y->right);
            }
            if(leftToRight)
            {
                ans.push_back(v);
                leftToRight = false;
            }
            else
            {
                reverse(v.begin(), v.end());
                ans.push_back(v);
                leftToRight = true;
            }
        }
        return ans;
    }
};
