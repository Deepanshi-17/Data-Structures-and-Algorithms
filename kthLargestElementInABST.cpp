/*TC -> O(N) + O(NlogK)
  SC -> O(N) + O(K)*/
class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        priority_queue<int,vector<int>,greater<int>>q;
        stack<Node*>st;
        st.push(root);
        while(!st.empty())
        {
            Node* x = st.top();
            st.pop();
            q.push(x->data);
            if(q.size() > K)
            q.pop();
            if(x->left)
            st.push(x->left);
            if(x->right)
            st.push(x->right);
        }
        return q.top();
    }
};

/*TC -> O(N)
  SC -> O(N)*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //KTH SMALLEST -> inorder;
        int counter = 0;
        stack<TreeNode*>st;
        int ans = 0;
        while(true)
        {
            if(root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                if(st.empty()) break;
                TreeNode* x = st.top();
                st.pop();
                counter++;
                if(counter == k)
                return x->val;
                root = x->right;
            }
        }
        return -1;
    }
};
