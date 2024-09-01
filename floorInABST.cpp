/*TC -> o(logn)
  SC -> O(1)
  */
class Solution{

public:
    int fun(Node* root, int x)
    {
        int val = -1;
        while(root)
        {
            if(root->data == x)
            return root->data;
            
            else if(root->data > x)
            {
                root = root->left;
            }
            else
            {
                val = root->data;
                root = root->right;
            }
        }
        return val;
    }
    int floor(Node* root, int x) {
       if(root == NULL) return -1;
       return fun(root, x);
    }
};
