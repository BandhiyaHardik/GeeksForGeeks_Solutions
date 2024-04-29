class Solution {
public:
    Node* deleteK(Node *head, int k) {
        if (k == 1) {
            return nullptr; 
        }
        
        Node* curr = head;
        Node* prev = nullptr;
        int count = 0;
        
        while (curr) {
            count++;
            if (count % k == 0) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                delete curr;
                curr = prev ? prev->next : head;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}