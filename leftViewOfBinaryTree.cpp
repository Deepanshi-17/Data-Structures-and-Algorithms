/*TC -> O(N)
  SC -> O(N) + O(N)
*/
vector<int> leftView(Node *root)
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
            if(i == 0)
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

/*TC -> O(log2N)
  SC -> O(log2N)
  */

void left_(Node* root, vector<int>& ans, int level)
{
    if(root == NULL)
    return;
    
    if(level == ans.size())
    {
        ans.push_back(root->data);
    }
    left_(root->left, ans, level + 1);
    left_(root->right, ans, level + 1);
}
vector<int> leftView(Node *root)
{
  if(root == NULL)
  return {};
  vector<int>ans;
  left_(root, ans, 0);
  return ans;
}
