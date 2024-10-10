class Solution {
  public:
    int maxDistance(vector<int> &arr) {

        unordered_map<int,int>mp;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()){
                maxi=max(maxi,i-mp[arr[i]]);
            }
            else {
                   mp[arr[i]]=i;
            }
        }
        return maxi;
    }
};