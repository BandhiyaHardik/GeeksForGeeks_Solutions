class Solution{
public:
    long long sequence(int n){
        const long long mod = 1e9 + 7;
        
        long long p = 1;
        long long ans = 0;
        
        for(int i = 1; i < n + 1; i++){
            long long val = 1;
            
            for(int j = 0; j < i; j++){
                val = (val * (p++)) % mod;
            }
            
            ans = (ans + val) % mod;
        }
        
        return ans;
    }
};