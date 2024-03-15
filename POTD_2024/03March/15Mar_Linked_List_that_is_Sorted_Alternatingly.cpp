class Solution
{
    public:
    
    Node* merge(Node *head1, Node* head2){
        if (!head1) return head2;  
    	if (!head2) return head1; 
    	
    	Node *temp = NULL;
    	
    	if (head1->data < head2->data)
    	{
    		temp = head1;     
    		head1->next = mergelist(head1->next, head2);
    	}
    	else
    	{
    		temp = head2;   
    		head2->next = mergelist(head1, head2->next);
    		
    	}
    	return temp;

    }
    
    void reverse(Node *&head){
        Node* prev=NULL, *curr=head, *next;
        
        while(curr){
            next=curr->next;
            curr->next= prev;
            prev = curr;
            curr=next;
        }
        head=prev;
    }
    
    void splitList(Node*head, Node **Ahead, Node**Dhead){
        *Ahead=new Node(0);
        *Dhead=new Node(0);
        
        Node*ascn= *Ahead;
        Node*dscn= *Dhead;
        Node* curr=head;
        while(curr){
            ascn->next=curr;
            ascn=ascn->next;
            curr=curr->next;
            
            if(curr){
                dscn->next=curr;
                dscn=dscn->next;
                curr=curr->next;
            }
        }
        
        ascn->next=NULL;
        dscn->next=NULL;
        
        *Ahead=(*Ahead)->next;
        *Dhead=(*Dhead)->next;
        
        return;
    }
    

    void sort(Node **head)
    {
    
         Node*Ahead, *Dhead;
         splitList(*head, &Ahead, &Dhead);
         
         reverse(Dhead);
         
         *head=merge(Ahead, Dhead);
         
         return;
    }
};