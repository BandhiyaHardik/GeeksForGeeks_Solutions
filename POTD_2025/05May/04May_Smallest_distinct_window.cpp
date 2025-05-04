class Solution {
  public:
    int findSubString(string& str) {

        set<char>s;
        for(char c: str) s.insert(c);
        int len=s.size();
        int ans=INT_MAX;
        int i=0,j=0;
        unordered_map<char,int>mp;
        while(j<str.size()){
            mp[str[j]]++;
            if(mp.size()>=len){
                while(mp[str[i]]>1){
                    mp[str[i]]--;
                    i++;
                }
                ans=min(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};