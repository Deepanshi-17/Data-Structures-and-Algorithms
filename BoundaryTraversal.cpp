/*TC -> O(N)
  SC -> O(H)*/
class Solution {
public:
    bool isLeaf(Node* root)
    {
        return !root->left && !root->right;
    }
    void addleft(Node* root, vector<int>& ans)
    {
        Node* curr = root;
       while(curr)
       {
           if(!isLeaf(curr))
           ans.push_back(curr->data);
           
           if(curr->left)
           curr = curr->left;
           else
           curr = curr->right;
       }
    }
    void addleaf(Node* root, vector<int>& ans)
    {
           if(root == NULL) return;
           if(isLeaf(root)){
           ans.push_back(root->data);
           return;}
           addleaf(root->left, ans);
           addleaf(root->right, ans);
    }
    void addright(Node* root, vector<int>& ans)
    {
       vector<int>temp;
       Node* curr = root;
       while(curr)
       {
           if(!isLeaf(curr))
           temp.push_back(curr->data);
           
           if(curr->right)
           curr = curr->right;
           else
           curr = curr->left;
       }
       for(int i = temp.size()-1; i>=0; i--)
       {
           ans.push_back(temp[i]);
       }
    }
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root == NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addleft(root->left, ans);
        addleaf(root, ans);
        addright(root->right, ans);
        return ans;
    }
};
