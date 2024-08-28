/*TC -> O(n) + O(n/2)
  SC -> O(1)*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            n++;
        }
        temp = head;
        int count = n/2;
        while(count--)
        {
            temp = temp->next;
        }
        return temp;
    }
};


/* TC -> O(n)
  SC -> O(1) */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
