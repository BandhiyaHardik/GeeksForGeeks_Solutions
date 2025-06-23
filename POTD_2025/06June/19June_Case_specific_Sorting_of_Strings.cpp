class Solution {
  public:
    string caseSort(string& s) {

        vector<int>upper(26,0);
        vector<int>lower(26,0);
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z') upper[s[i]-'A']++;
            else lower[s[i]-'a']++;
        }
        int u=0,l=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                while(upper[u]==0)u++;
                s[i]=char(u+'A');
                upper[u]--;
                u=0;
            }
            else{
               while(lower[l]==0)l++;
                s[i]=char(l+'a');
                lower[l]--;
                l=0; 
            }
        }
        return s;
    }
};