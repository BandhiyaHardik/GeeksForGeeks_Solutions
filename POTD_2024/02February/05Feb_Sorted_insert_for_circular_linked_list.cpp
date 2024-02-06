class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
        if(!head){
            Node * new_node = new Node(data);
            new_node -> next = new_node;
            
            return new_node;
        }
    
        Node * cur = head; 
        
        while(1){
            if(data >= cur -> data and data <= cur -> next -> data){
                Node * new_node = new Node(data);
                new_node -> next = cur -> next;
                cur -> next = new_node;
                
                break;
            }
            
            if(cur -> next != head)
                cur = cur -> next;
            else{
                Node * new_node = new Node(data);
                cur -> next = new_node;
                new_node -> next = head;
                
                if(data <= head -> data)
                    head = new_node;
                
                break;
            }
        }
       
       return head;
    }
};