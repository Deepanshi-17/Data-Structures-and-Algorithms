/*TC -> O(log2N)
  SC->O(log2N)
  */
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void fun(Node* root, vector<int>& ans, int level)
    {
        if(root == NULL)
        return;
        if(level == ans.size())
        {
            ans.push_back(root->data);
        }
        fun(root->right, ans, level + 1);
        fun(root->left, ans, level + 1);
    }
    vector<int> rightView(Node *root)
    {
        if(root == NULL) return {};
       vector<int>ans;
       fun(root, ans, 0);
       return ans;
    }
};

/*TC -> O(N)
  SC -> O(N)
  */
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
           vector<int>ans;
            queue<Node*>q;
            q.push(root);
            while(!q.empty())
            {
                int x = q.size();
                for(int i = 0; i < x; i++)
                {
                    Node* nod = q.front();
                    q.pop();
                    if(i == x-1)
                    {
                        ans.push_back(nod->data);
                    }
                    if(nod->left)
                    q.push(nod->left);
                    if(nod->right)
                    q.push(nod->right);
                }
            }
            return ans;
    }
};
