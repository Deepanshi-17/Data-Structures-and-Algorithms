/*TC -> O(N) + O(Nlogn) + O(n)
  SC -> O(N) + O(n) */
class Solution {
  public:
    vector<int> bottomView(Node *root)
    {
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node* curr = it.first;
            int col = it.second;
            mp[col] = curr->data;
            if(curr->left)
            q.push({curr->left, col-1});
            if(curr->right)
            q.push({curr->right, col + 1});
        }
        
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
