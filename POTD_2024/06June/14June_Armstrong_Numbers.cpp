class Solution {
public:
    string armstrongNumber(int n) {

        int original = n;
        int sum = 0;
        
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit * digit;
            n /= 10;
        }
   
        if (sum == original) {
            return "true";
        } else {
            return "false";
        }
    }
};