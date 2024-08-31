/*TC -> O(N)
  SC -> O(N)*/

stack<int> levelOrder(Node* root)
    {
    	stack<int>st;
    	queue<Node*>q;
    	q.push(root);
    	while(!q.empty())
    	{
    	    int x = q.size();
    	    while(x--)
    	    {
    	        Node* y = q.front();
    	        q.pop();
    	        st.push(y->data);
    	        if(y->right)
    	        q.push(y->right);
    	        if(y->left)
    	        q.push(y->left);
    	    }
    	}
    	return st;
    }
vector<int> reverseLevelOrder(Node *root)
{
    stack<int>st = levelOrder(root);
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

    vector<int> levelOrder(Node* root)
    {
    	vector<int>st;
    	queue<Node*>q;
    	q.push(root);
    	while(!q.empty())
    	{
    	    int x = q.size();
    	    while(x--)
    	    {
    	        Node* y = q.front();
    	        q.pop();
    	        st.insert(st.begin(), y->data);
    	        if(y->right)
    	        q.push(y->right);
    	        if(y->left)
    	        q.push(y->left);
    	    }
    	}
    	return st;
    }
vector<int> reverseLevelOrder(Node *root)
{
    vector<int>st = levelOrder(root);
    return st;
}
