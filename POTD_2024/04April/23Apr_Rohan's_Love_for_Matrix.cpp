class Solution {
  public:
    int firstElement(int n) {

        if(n==0 || n==1) return 1;
        int a=1, b=1;
        int mod= 1000000007;
        int c;
        for(int i=0;i<n-2;i++){
            c=(a+b)%mod;
            a=b%mod;
            b=c%mod;
        }
        return c%mod;
    }
};