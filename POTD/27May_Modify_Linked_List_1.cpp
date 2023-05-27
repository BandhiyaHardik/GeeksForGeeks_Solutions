class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
     Node* mid = get_m(head);
    
    Node* backlist = mid->next; 
    mid->next = nullptr; 

    backlist = reverse(backlist);

    Node* curr1 = head;
    Node* curr2 = backlist;
    while (curr2 != nullptr) {
        int temp = curr1->data;
        curr1->data = curr2->data - temp;
        curr2->data = temp;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    mid->next = reverse(backlist);
    return head;
}

Node* get_m(Node* head) {
    Node* f = head;
    Node* s = head;
    while (f->next != nullptr && f->next->next != nullptr) {
        s = s->next;
        f = f->next->next;
    }
    return s;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;

        curr = next;
    }
    return prev;
}
};