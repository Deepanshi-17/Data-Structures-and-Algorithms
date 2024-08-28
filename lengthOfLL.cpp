/*TC -> O(N)
  SC -> O(1)
  */
class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int count = 0;
        struct Node* temp = head;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
