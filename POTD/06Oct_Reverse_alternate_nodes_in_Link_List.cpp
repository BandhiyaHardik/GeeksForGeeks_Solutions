class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        if (odd->next == nullptr)
            return;

        Node* h1 = odd;
        Node* h2 = odd->next;
        Node* t1 = h1, *t2 = h2;

        while (true) {
            t1->next = t1->next->next;
            t1 = t1->next;

            if (t2->next->next == nullptr) {
                t1->next = nullptr;
                break;
            }

            t2->next = t1->next;
            t2 = t2->next;

            if (t1->next->next == nullptr) {
                t1->next = nullptr;
                break;
            }
        }

        t2->next = nullptr;
        t1->next = reverse(h2);
    }

     Node* reverse(Node* head) {
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};