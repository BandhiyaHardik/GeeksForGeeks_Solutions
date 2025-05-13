class Solution {
  public:
    int nCr(int n, int r) {

        if(r>n) return 0;
        long long ans=1;
        for(int i=1;i<=r;i++) ans=ans*(n-r+i)/i;
        return (int) ans;     
    }
};