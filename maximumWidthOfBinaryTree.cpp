/*TC-> O(N)
  SC-> O(N)
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        long long maxi = 0;
        while(!q.empty())
        {
            long long start = q.front().second;
            long long end = q.back().second;
            long long size = q.size();
            maxi = max(maxi, end-start + 1);
            for(int i = 0; i< size; i++)
            {
                auto it = q.front();
                long long idx = it.second - start;
                q.pop();
                if(it.first->left)
                {
                    q.push({it.first->left, (long long)2*idx + 1});
                }
                if(it.first->right)
                {
                    q.push({it.first->right, (long long)2*idx + 2});
                }
            }
        }
        return (int)maxi;
    }
};
