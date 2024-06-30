class Solution {
  public:
    Node* deleteNode(Node* head, int x) {

        if(x==1)return head->next;
        Node *temp=head;
        int count=1;
        while(count<x){
            temp=temp->next;
            count++;
        }
        temp->prev->next=temp->next;
        if(temp->next)temp->next->prev=temp->prev;
        return head;
    }
};