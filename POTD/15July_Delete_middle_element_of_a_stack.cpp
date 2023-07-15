class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        helper(s, sizeOfStack, 0);
    }
    void helper(std::stack<int>& s, int n, int idx) {
        if (idx == n/2)
        {
            s.pop();
            return;
        }
        
        int x = s.top();
        s.pop();
        idx++;
        
        helper(s, n, idx);
        
        s.push(x);
    }
};