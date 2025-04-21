class Solution {
  public:
    int missingNum(vector<int>& arr) {

        int n=arr.size()+1;
        int ogsum=0;
        for(int i=1;i<=n;i++)ogsum+=i;
        int actualsum=0;
        for(int i=0;i<arr.size();i++)actualsum+=arr[i];
        return ogsum-actualsum;
    }
};