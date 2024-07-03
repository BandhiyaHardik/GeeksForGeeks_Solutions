class Solution {
  public:
   Node* removeAllDuplicates(struct Node* head) {

        if(!head->next)return head;
        Node *ans=new Node(-1),*prev=head;
        Node *temp=ans;
        head=head->next;
        int count=1;
        while(head){
            if(prev->data==head->data)count++;
            else if(count==1){
                temp->next=prev;
                temp=temp->next;
            }
            else count=1;
            prev=head;
            head=head->next;
        }
        if(count==1)temp->next=prev;
        else temp->next=NULL;
        return ans->next;
    }
};