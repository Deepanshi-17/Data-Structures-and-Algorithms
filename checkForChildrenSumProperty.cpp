/*TC -> O(N)
  SC -> O(H)*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int fun(Node* root)
    {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL)
        return true;
        int sum = 0;
        if(root->left != NULL)
        {
            sum += root->left->data;
        }
        if(root->right != NULL)
        {
            sum += root->right->data;
        }
        
        return (root->data == sum) && fun(root->left) && fun(root->right);
    }
    int isSumProperty(Node *root)
    {
        if(root == NULL) return 0;
        return fun(root);
    }
};
