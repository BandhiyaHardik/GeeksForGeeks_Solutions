class Solution {
public:
    Node * reverse(Node * head) {
        Node * prev = nullptr, * cur = head;
        
        while(cur){
            Node * next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    pair<Node *, Node *> subtract(Node * head1, Node * head2) {
        LinkedList ans, second;
        int carry = 0;
        
        while(head1 or head2){
            int cur = (head1 ? head1 -> data : 0) - (head2 ? head2 -> data : 0) - carry;
            carry = cur < 0;
            
            if(carry){
                if((head1 and head1 -> next) or (head2 and head2 -> next)){
                    ans.insert(10 + cur);
                    second.insert(0);
                }
                else{
                    second.insert(abs(cur));
                }
            }
            else{
                ans.insert(cur);
                second.insert(0);
            }
            
            if(head1)
                head1 = head1 -> next;
            if(head2)
                head2 = head2 -> next;
        }
        
        
        if(carry){
            return {second.head, ans.head};
        }
        else{
            return {ans.head, nullptr}; 
        }  
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        pair<Node *, Node *> res = subtract(head1, head2);
        Node * final_ans;
        
        if(res.second){
            head1 = res.first;
            head2 = res.second;
            
            final_ans = subtract(head1, head2).first;
        }
        else{
            final_ans = res.first;
        }
        
        final_ans = reverse(final_ans);
        
        while(final_ans -> data == 0 and final_ans -> next)
            final_ans = final_ans -> next;
        
        return final_ans;
    }
};