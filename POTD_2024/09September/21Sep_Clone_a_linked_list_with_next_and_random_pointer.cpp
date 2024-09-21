class Solution {
  public:
    Node *copyList(Node *head) {

        if(head==NULL) return head;
        Node * temp=head;
        while(temp){
            Node *n=new Node(temp->data);
            n->next=temp->next;
            temp->next=n;
            temp=n->next;
        }

        temp=head;
        Node *head2=temp->next;
        while(temp!=NULL){
            if(temp->random==NULL){
                temp->next->random=NULL;
            }
            else
            temp->next->random=temp->random->next;
            temp=temp->next->next;
        }

        temp = head;
        while(temp!=NULL){
            Node * temp2=temp->next;
            temp->next=temp2->next;
            if(temp2->next)
            temp2->next=temp2->next->next;
            temp=temp->next;
        }
        return head2;
    }
};