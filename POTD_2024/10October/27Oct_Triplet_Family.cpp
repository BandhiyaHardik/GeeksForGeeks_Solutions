class Solution {
  public:
    bool findTriplet(vector<int>& arr) {

        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<arr.size();i++){
            int target=arr[i];
            int start=i+1;
            int end=arr.size()-1;
            while(start<end){
                if(arr[start]+arr[end]==target) return true;
                else if(arr[start]+arr[end]>target) start++;
                else end--;
            }
        }
        return false;
    }
};