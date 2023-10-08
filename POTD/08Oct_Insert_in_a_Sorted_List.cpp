class Solution{
  public:
    // Should return head of the modified linked list
      Node *sortedInsert(struct Node* head, int data) {
        if(data < head->data)
        {
            Node*newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            return head;
        }
        Node*temp = head;
        Node*prev = NULL;
        while(temp!= NULL and temp->data <= data)
        {
           prev = temp;
           temp = temp->next;
        }
        Node* newNode = new Node(data);
        newNode->next = temp;
        prev->next = newNode;
        return head;
    }
};
