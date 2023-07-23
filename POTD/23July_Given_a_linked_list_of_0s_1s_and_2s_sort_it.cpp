class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int cnt[3] = {0};

    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        if (curr->data == 0)
            cnt[0]++;
        else if (curr->data == 1)
            cnt[1]++;
        else
            cnt[2]++;
    }

    Node* curr = head;
    int idx = 0;
    while (curr != nullptr) {
        if (cnt[idx] == 0)
            idx++;

        if (cnt[idx] != 0) {
            curr->data = idx;
            cnt[idx]--;
            curr = curr->next;
        }
    }

    return head;
        
    }
};