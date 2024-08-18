class Solution {
  public:
    bool canSplit(vector<int>& arr) {

        int arrSum=0,subArrSum=0,n=arr.size();
        for(int i=0;i<n;i++){
            arrSum+=arr[i];
        }
        for(int i=0;i<n;i++){
            subArrSum+=arr[i];
            if(subArrSum*2==arrSum) return true;
        }
        return false;
    }
};