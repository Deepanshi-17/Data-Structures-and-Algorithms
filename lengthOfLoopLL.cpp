/*TC -> O(N)
  SC -> O(N)
  */
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        int t = 1;
        unordered_map<Node*,int>mp;
        Node* temp = head;
        while(temp->next)
        {
            if(mp.find(temp) != mp.end())
            {
                return (t - mp[temp]);
            }
            mp.insert({temp, t});
            t++;
            temp = temp->next;
        }
        return 0;
    }
};

/*TC -> O(N)
  SC -> O(1) */
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                int cnt = 1;
                fast = fast->next;
                while(slow != fast)
                {
                    fast = fast->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
};
