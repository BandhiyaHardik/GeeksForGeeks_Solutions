class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        vector<int> f(26, 0);
        
        for(auto i : s){
            char cur = tolower(i);
            
            if(cur >= 'a' and cur <= 'z'){
                f[cur - 'a'] = 1;
            }
        }
            
        return accumulate(f.begin(), f.end(), 0) == 26;
    }

};
