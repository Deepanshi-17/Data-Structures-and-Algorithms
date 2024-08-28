/*TC -> O(1) SC -> O(1) */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        temp->val = temp->next->val;
        temp->next = temp->next->next;
    }
};
