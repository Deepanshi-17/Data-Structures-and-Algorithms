/*TC -> O(n)
  SC -> O(1)
  */
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        Node* zerohead = new Node(-1);
        Node* onehead = new Node(-1);
        Node* twohead = new Node(-1);
        Node* zerotail = zerohead;
        Node* onetail = onehead;
        Node* twotail = twohead;
        
        Node* curr = head;
        Node* temp;
        while(curr)
        {
            temp = curr;
            curr = curr->next;
            temp->next = NULL;
            
            if(temp->data == 0)
            {
                zerotail->next = temp;
                zerotail = zerotail->next;
            }
            else if(temp->data == 1)
            {
                onetail->next = temp;
                onetail = onetail->next;
            }
            else
            {
                twotail->next = temp;
                twotail = twotail->next;
            }
        }
        if (onehead->next) {
            zerotail->next = onehead->next; // 0s list to 1s list
        } else {
            zerotail->next = twohead->next; // If 1s list is empty, connect directly to 2s list
        }

        onetail->next = twohead->next; // 1s list to 2s list

        // The new head is the start of the 0s list (skip dummy node)
        return zerohead->next;
        
    }
};
