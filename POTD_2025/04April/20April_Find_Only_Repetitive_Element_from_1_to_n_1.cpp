class Solution {
  public:
    int findDuplicate(vector<int>& arr) {

        int n=arr.size();
        int ogsum=0;
        for(int i=1;i<n;i++) ogsum+=i;
        int actualsum=0;
        for(int i=0;i<n;i++) actualsum+=arr[i];
        return actualsum-ogsum;        
    }
};