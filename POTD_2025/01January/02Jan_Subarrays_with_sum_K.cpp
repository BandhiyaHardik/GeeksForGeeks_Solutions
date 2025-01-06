class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {

        unordered_map<int,int>mp;
        int sum=0,count=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k) count++;
            if(mp.find(sum-k)!=mp.end()) count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};