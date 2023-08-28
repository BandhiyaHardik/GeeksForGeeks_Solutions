Node *removeDuplicates(Node *head)

{
 Node *t=head;

 while(t->next){

     if(t->data==t->next->data){

         t->next=t->next->next;

     }else{

     t=t->next;

     }

 }return head;

}