class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node* prev = head;
        Node* curr = head->next;

        head = curr;

        while (true) {
            Node* next = curr->next;
            curr->next = prev;

            if (next == nullptr || next->next == nullptr) {
                prev->next = next;
                break;
            } else {
                prev->next = next->next;
            }

            prev = next;
            curr = next->next;
        }

        return head;
    }
};