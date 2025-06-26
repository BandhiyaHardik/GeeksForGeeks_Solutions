class Solution {
  public:
    int minValue(string &s, int k) {

        vector<int>freq(26,0);
        for(char c : s) freq[c-'a']++;
        int maxi=INT_MIN;
        map<int,int>mp;
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0)mp[freq[i]]++;
            maxi=max(maxi,freq[i]);
        }
        while(k>0 && maxi>0){
            int remov=min(k,mp[maxi]);
            mp[maxi]-=remov;
            mp[maxi-1]+=remov;
            if(mp[maxi]==0) mp.erase(maxi--);
            k-=remov;
        }
        int value=0;
        for(auto& it : mp){
            value+=it.first*it.first*it.second;
        }
        return value;
    }
};