class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int index = 0;
        int ans = 0;
        bool neg = 0;
        
        if(s[index] == '-'){
            neg = 1;
            ++index;
        }
        
        
        for(; index < s.size(); index++){
            if(isdigit(s[index])){
                ans *= 10;
                ans += (s[index] - '0');
            }
            else{
                return -1;
            }
        }
        
        return ans * (neg ? -1 : 1);
    }
};