/*TC -> O(nlogK)
  sc -> o(n) */

void fun(vector<int>& v, int k)
{
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i = 0; i <=k && i < v.size(); i++)
    {
        q.push(v[i]);
    }
    int index = 0;
    for(int i = k + 1; i < v.size(); i++)
    {
        v[index++] = q.top();
        q.pop();

        q.push(v[i]);
    }

    while(!q.empty())
    {
        v[index++] = q.top();
        q.pop();
    }
}
