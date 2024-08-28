/*TC -> O(N)
  SC -> O(N)
*/
class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i = 1; i < arr.size(); i++)
        {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        return head;
    }
};
