class Solution {
  public:
    bool divby13(string &s) {

        int num=0;
        for(int i=0;i<s.size();i++){
            num=(num*10 + s[i]-'0')%13;
        }
        return num==0;
    }
};