#include <vector>
#include <queue>
#include <map>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void createMapping(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }

    void fun(TreeNode* target, map<TreeNode*, TreeNode*>& mp, vector<int>& ans, int k) {
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            if (level == k) {
                while (size--) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return; // No need to process further levels
            }
            
            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                // Add children to the queue
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }

                // Add parent to the queue
                if (mp[node] && !visited[mp[node]]) {
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                }
            }
            level++;
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        createMapping(root, mp);
        vector<int> ans;
        fun(target, mp, ans, k);
        return ans;
    }
};
