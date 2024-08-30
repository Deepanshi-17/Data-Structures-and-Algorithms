/*TC -> O(2 * max(length of l1, length of l2))
  SC -> O(1)*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA != tempB)
        {
            tempA = (tempA == NULL)? headB: tempA->next;
            tempB = (tempB == NULL)? headA: tempB->next;
        }
        return tempA;
    }
};

 /*TC -> O(N + M)
 SC-> O(N)*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA != tempB)
        {
            tempA = tempA->next;
            if(tempA == NULL)
            {
                tempA = headB;
            }
            tempB = tempB->next;
            if(tempB == NULL)
            {
                tempB = headA;
            }
        }
        return tempA;
    }
};
