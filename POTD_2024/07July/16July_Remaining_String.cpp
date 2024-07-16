class Solution {
  public:

    string printString(string s, char ch, int count) {

        int occur=0;
        int i;
        for(i=0;i<s.size();i++){
            if(s[i]==ch){
                occur++;
            }
            if(occur==count)
            break;
        }
        if(i<s.size()-1){
            return s.substr(i+1,s.size()-(i+1));
        }
        else{
            return "";
        }
        
    }
};