class Solution{
public:
    int findWinner(int n, int A[]){
        int val = 0;
        
        for(int i = 0; i < n; i++)
            val ^= A[i];
        
        return ((n & 1) and val > 0) ? 2 : 1;
    }
};