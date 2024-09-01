/*TC -> O(N)
  SC -> O(N)
  */
class Solution {
public:
TreeNode* fun(int startpost, int endpost, vector<int>& postorder, int startin, int endin, vector<int>& inorder, map<int,int>& mp)
    {
        if(startpost > endpost || startin > endin) return NULL;

        TreeNode* root = new TreeNode(postorder[endpost]);
        int rootposinorder = mp[postorder[endpost]];
        int numsleft = rootposinorder - startin;
        root->left = fun(startpost, startpost + numsleft - 1, postorder, startin, rootposinorder - 1, inorder, mp);
        root->right = fun(startpost + numsleft, endpost-1, postorder, rootposinorder + 1, endin, inorder, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return fun(0, postorder.size()-1, postorder, 0, inorder.size()-1, inorder, mp);
    }
};
