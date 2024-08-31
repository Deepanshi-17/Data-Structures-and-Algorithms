/*TC -> O(N*H)
  SC -> O(N*H)*/
class Solution {
  public:
    void fun(Node* root, vector<vector<int>>& ans, vector<int>v)
    {
        if(root->left == NULL && root->right == NULL)
        {
            v.push_back(root->data);
            ans.push_back(v);
            return;
        }
        v.push_back(root->data);
        if(root->left)
        fun(root->left, ans, v);
        if(root->right)
        fun(root->right, ans, v);
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        vector<int>v;
        fun(root, ans, v);
        return ans;
    }
};
