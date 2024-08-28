/*TC -> O(nlogk)
  SC -> O(n) */

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	   priority_queue<int,vector<int>,greater<int>>q;
	   vector<int>ans;
	   for(int i = 0; i < n; i++)
	   {
	       q.push(arr[i]);
	       if(q.size() > k)
	       q.pop();
	   }
	   
	   while(!q.empty())
	   {
	       ans.push_back(q.top());
	       q.pop();
	   }
	   reverse(ans.begin(), ans.end());
	   return ans;
	}

};
