class Solution{
    public:
        int modulo(string s,int m){
            int k = 0;
        for (int i = 0; i < s.length(); i++) {
            k = (k << 1) + (s[i] - '0'); 
            k %= m; 

        }
        return k;
        }
};
