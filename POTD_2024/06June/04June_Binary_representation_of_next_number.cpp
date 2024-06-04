class Solution {
  public:
     string binaryNextNumber(string s) {
        bool indication=true;
        for(int i=s.length();i>=0;i--){
            if(s[i]=='0'){
                indication=false;
                s[i]='1';
                break;
            }
            else s[i]='0';
        }
        if(indication){
            s='1'+s;
        }
        else{
            while(s[0]=='0')s.erase(s.begin());
        }
        return s;
    }
};