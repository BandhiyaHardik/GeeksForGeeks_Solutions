class Solution {
  public:
     /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {

        if(!head|| n<=0) return 0;
        Node *fast=head, *slow=head;
        
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        int sum=0;
        while(slow){
            sum=sum+slow->data;
            slow=slow->next;
        }
        return sum;
    }
};