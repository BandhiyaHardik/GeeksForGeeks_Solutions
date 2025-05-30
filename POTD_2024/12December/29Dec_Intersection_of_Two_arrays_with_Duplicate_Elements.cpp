class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {

        unordered_map<int,int>mp;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<b.size();i++){
            if(mp[b[i]]>0) ans.push_back(b[i]);
            mp[b[i]]=-1;
        }
        return ans;
    }
};