/*TC -> O(N)
  SC -> O(N)
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
};
