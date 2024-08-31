/*TC -> O(N)
  SC -> O(H)
  */
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool fun(Node* root, int mini, int maxi)
    {
        if(root == NULL) return true;
        if(root->data <= mini || root->data >= maxi)
        return false;
        return fun(root->left, mini, root->data) && fun(root->right, root->data, maxi);
    }
    bool isBST(Node* root) {
        return fun(root, -1e9, 1e9);
    }
};
