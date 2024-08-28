/* TC -> O(N)
 SC -> O(1)
*/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        if(head->next->next == NULL)
        {
            head->next = NULL;
            return head;
        };
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->val = slow->next->val;
        slow->next = slow->next->next;
        return head;
    }
};
