class Solution{
  public:
    char nthCharacter(string s, int r, int n) {

        if(r==0) return s[n];
        
        char c= nthCharacter(s, r-1, n/2);
        
        if(n%2==1){
            if(c=='0'){
                return '1';
            }
            else{
                return '0';
            }
        }
        else{
            if(c=='0'){
                return '0';
            }
            else{
                return '1';
            }
        }
    }
};