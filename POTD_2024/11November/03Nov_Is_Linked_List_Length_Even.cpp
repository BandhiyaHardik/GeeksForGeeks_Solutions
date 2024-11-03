class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        
        Node* temp= *head;
        int count=0;
        
        while(temp){
            temp=temp->next;
            count++;
        }
        
        return (count%2==0);
        
    }
};