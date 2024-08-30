/*
TC -> O(N) + O(N)
SC -> O(N)
*/

class Solution {
  public:
    Node* reverse(Node* head)
    {
        if(head == NULL || head->next == NULL) return head;
        Node* prev = NULL;
        Node* temp = head;
        Node* next = head->next;
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
    Node* addOne(Node* head) {
        Node* h1 = reverse(head);
        Node* dummy = new Node(-1);
        Node* final = dummy;
        int carry = 1;
        while(h1 || carry)
        {
            int sum = 0;
            if(h1){
            sum += h1->data;
                h1 = h1->next;
            }
            sum += carry;
            carry = sum/10;
            dummy->next = new Node(sum % 10);
            dummy = dummy->next;
        }
        return reverse(final->next);
    }
};
