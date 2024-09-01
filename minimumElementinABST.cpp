/*TC -> 
  SC ->
  */
class Solution {
  public:
    int fun(Node* root)
    {
        while(root->left != NULL)
        {
            root = root->left;
        }
        return root->data;
    }
    int minValue(Node* root) {
        if(root->left == NULL) return root->data;
        return fun(root);
    }
};
