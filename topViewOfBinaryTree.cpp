/*TC -> O(N) + O(NlogN) + O(N)
  SC -> o(N) + o(N)
  */
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
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
            
            if(mp.find(col) == mp.end())
            {
                mp[col] = curr->data;
            }
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
