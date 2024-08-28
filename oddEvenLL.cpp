/* TC -> O(n)
  SC -> O(1) */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddhead = new ListNode(-1);
        ListNode* evenhead = new ListNode(-1);
        ListNode* oddtail = oddhead;
        ListNode* eventail = evenhead;
        int cnt = 1;
        ListNode* curr = head;
        ListNode* temp;
        while(curr)
        {
            temp = curr;
            curr = curr->next;
            temp->next = NULL;

            if(cnt % 2 != 0)
            {
                oddtail->next = temp;
                oddtail = oddtail->next;
            }
            else
            {
                eventail->next = temp;
                eventail = eventail->next;
            }
            cnt++;
        }

        oddtail->next = evenhead->next;
        return oddhead->next;
    }
};
