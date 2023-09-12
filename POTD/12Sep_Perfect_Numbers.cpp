class Solution {
  public:
    int isPerfectNumber(long long n) {
         if (n == 1)
            return 0;

        long sum = 1;
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) { 
                    sum += n / i;
                }
            }
        }

        return sum == n ? 1 : 0;
    }
};
