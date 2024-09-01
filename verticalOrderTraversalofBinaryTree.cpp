/*TC -> O(nlogn)
  sc -> o(n)*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode* nod = it.first;
            int col = it.second.first;
            int row = it.second.second;

            mp[col][row].insert(nod->val);

            if(nod->left)
            q.push({nod->left,{col - 1 ,row + 1}});
            if(nod->right)
            q.push({nod->right,{col + 1, row + 1}});
        }

        vector<vector<int>>ans;
        for(auto it: mp)
        {
            vector<int>col;
            for(auto p: it.second)
            {
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
