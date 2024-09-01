/*TC -> O(n)
  SC -> O(n) */
class Solution {
  public:
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>& mp)
    {
        Node* res = NULL;
        queue<Node*>q;
        q.push(root);
        mp[root] = NULL;
        
        while(!q.empty())
        {
            Node* x = q.front();
            q.pop();
            if(x->data == target)
            res = x;
            if(x->left)
            {
                q.push(x->left);
                mp[x->left] = x;
            }
            if(x->right)
            {
                q.push(x->right);
                mp[x->right] = x;
            }
        }
        return res;
    }
    
    int burnTree(map<Node*, Node*>& mp, Node* target)
    {
        map<Node*,bool>visited;
        visited[target] = true;
        int ans = 0;
        queue<Node*>q;
        q.push(target);
        while(!q.empty())
        {
            
            int x = q.size();
            bool burn = false;
            while(x--)
            {
                Node* y = q.front();
                q.pop();
            
                if(y->left && visited.find(y->left) == visited.end())
                {
                    q.push(y->left);
                    visited[y->left] = true;
                    burn = true;
                }
                if(y->right && visited.find(y->right) == visited.end())
                {
                    q.push(y->right);
                    visited[y->right] = true;
                    burn = true;
                }
                if(mp[y] && visited.find(mp[y]) == visited.end())
                {
                    q.push(mp[y]);
                    visited[mp[y]] = true;
                    burn = true;
                }
            }
            if(burn)
            ans++;
            
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        if(root == NULL)
        return 0;
        map<Node*, Node*>mp;
        Node* targetNode = createParentMapping(root, target, mp);
        if(targetNode == NULL) return 0;
        int ans = burnTree(mp, targetNode);
        return ans;
    }
};
