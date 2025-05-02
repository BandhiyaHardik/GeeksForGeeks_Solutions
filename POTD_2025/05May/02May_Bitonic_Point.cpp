class Solution {
  public:
    int findMaximum(vector<int> &arr) {

        int ans=-1;
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else if(arr[mid]>arr[mid+1]){
                ans=arr[mid];
                e=mid-1;
            }
        }
        return ans;
    }
};