class Solution {
  public:

    int missingNumber(int n, vector<int>& arr) {

        long long sum=n*(n+1)/2;
        long long sum2=0;
        for(int i=0;i<arr.size();i++){
            sum2+=arr[i];
        }
        return int(sum-sum2);
    }
};