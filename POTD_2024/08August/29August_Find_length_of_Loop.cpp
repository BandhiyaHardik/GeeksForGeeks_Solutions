class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        Node *slow=head, *fast = head->next;
        while(fast and fast->next){
            slow=slow->next;
            fast = fast->next->next;
            if(slow==fast)break;
        }
        if(!fast or !fast->next)return 0;
        int ans=0;
        Node *temp = slow->next;
        while(temp!=slow){
            temp=temp->next;
            ans++;
        }
        return ans+1;
    }
};