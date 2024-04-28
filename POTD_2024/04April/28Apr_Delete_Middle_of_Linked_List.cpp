class Solution{
public:
    Node* deleteMid(Node* head)
    {
        if (head == nullptr || head->next == nullptr) 
            return nullptr;

        Node* fast = head;
        Node* slow = head;
        Node* prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if (prev) {
            prev->next = slow->next;
        } else {
            head = head->next; 
        }

        delete slow; 
        return head;
    }
};
