class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
     if(n>0 && (n&(n-1))==0)
        return true;
        
        return false;
        
    }
};