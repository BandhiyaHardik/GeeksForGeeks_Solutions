class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
            long long ans = 0;
            
            while(head){
                ans = (ans * 2LL) % MOD;
                
                ans = (ans + head -> data) % MOD;
                
                head = head -> next;
            }
            
            return ans;
        }
};