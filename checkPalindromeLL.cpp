/*TC -> O(N) + O(N/2) + O(N/2)
  SC -> O(1)
  */
class Solution {
public:
    ListNode* fun(ListNode* prev, ListNode* temp, ListNode* next)
    {
        if(next == NULL){
            temp->next = prev;
            return temp;
        } 
        temp->next = prev;
        return fun(temp, next, next->next);
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        return fun(NULL, head, head->next);
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = reverseList(slow);
        while(temp->next)
        {
            if(head->val != temp->val) return false;
            head = head->next;
            temp = temp->next;
        }
        return true;
    }
};
