class Solution
{
    public:
     Node* compute(Node* head) {
        Node* new_head = rev(head);
        Node* curr = new_head;
        Node* temp = nullptr;
        Node* maxNode = curr;
        
        while (curr->next != nullptr) {
            if (curr->next->data < maxNode->data) {
                temp = curr->next;
                curr->next = temp->next;
            } else {
                curr = curr->next;
                maxNode = curr;
            }
        }
        
        return rev(new_head);
    }
    
    Node* rev(Node* head) {
        Node* prev = nullptr;
        Node* next = nullptr;
        Node* curr = head;
        
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
};