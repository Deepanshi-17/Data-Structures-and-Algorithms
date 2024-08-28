/*TC -> O(N)
  SC -> O(1)
  */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* next = head->next;
        while(next)
        {
            temp->next = prev;
            prev = temp;
            temp = next;
            next = next->next;
        }
        temp->next = prev;
        return temp;
    }
};
