/*TC -> O(N)
  SC -> O(N)
  */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>st;
        ListNode* temp = head;
        while(temp)
        {
            if(st.find(temp) != st.end())
            return true;
            st.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};

/*TC -> O(N)
  SC -> O(1) */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
