class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {

        vector<string>v;
        string word="";
        for(int i=0;i<str.size();i++){
            if(str[i]!='.') word+=str[i];
            else{
                v.push_back(word);
                word="";
            }
        }
        v.push_back(word);
        string ans="";
        for(int i=v.size()-1;i>=0;i--){
            ans+=v[i];
            if(i!=0) ans+=".";
        }
        return ans;
        
    }
};