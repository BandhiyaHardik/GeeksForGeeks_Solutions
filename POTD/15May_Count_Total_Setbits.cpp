class Solution {
  public:
   long larPowOf2(long n) {
    long x = 0;
    while(pow(2, x) <= n)
        x++;
    return x - 1;
}

long countBits(long n) {
    if(n==0)
        return 0;
        
    long x = larPowOf2(n);
    long y = x * (1 << (x - 1));
    long z = n - (1 << x);
    return y + z + 1 + countBits(z);
}

};