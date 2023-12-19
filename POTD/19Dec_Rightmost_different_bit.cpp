class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        for(int i = 0; i < 32; i++){
            int x = (m >> i) & 1;
            int y = (n >> i) & 1;
            
            if(x != y)
                return i + 1;
        }
        
        return -1;
    }
};