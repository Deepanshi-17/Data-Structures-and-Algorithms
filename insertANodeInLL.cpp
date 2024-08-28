/*TC -> o(N)
  SC -> o(1)
  */
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        if(head == NULL)
        return new Node(x);
        Node* temp = head;
        while(temp->next != NULL)
        temp = temp->next;
        
        temp->next = new Node(x);
        return head;
    }
};
