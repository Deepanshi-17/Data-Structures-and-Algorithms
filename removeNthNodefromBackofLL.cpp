/*TC -> O(N) + O(N/2)
  SC -> O(1)
  */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        if(head->next == NULL && n == 1) return NULL;
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        if(len == n)
        return head->next;
        int x = len - n - 1;
        temp = head;
        while(x--)
        temp = temp->next;
        
        if(temp->next->next == NULL)
        {
            temp->next = NULL;
        }
        else temp->next = temp->next->next;
        return head;
    }
};

/*TC -> O(N)
SC -> O(1)*/
  class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || (head->next == NULL && n == 1)) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(n--)
        {
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if(slow->next->next == NULL)
        slow->next = NULL;
        else
        slow->next = slow->next->next;
        return head;
    }
};
