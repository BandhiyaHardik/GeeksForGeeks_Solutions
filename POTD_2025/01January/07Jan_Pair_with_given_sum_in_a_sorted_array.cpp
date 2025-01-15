class Solution {
  public:
     int countPairs(vector<int> &arr, int target) {

        int i=0,j=arr.size()-1,ans=0;
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum==target){
                if(arr[i]==arr[j]){
                    int temp = j-i;
                    ans+=(temp*(temp+1))/2;
                    break;
                }
                else{
                    int left=1,right=1;
                    while(i<j and arr[i]==arr[i+1]){
                        left++;
                        i++;
                    }
                    while(i<j and arr[j]==arr[j-1]){
                        right++;
                        j--;
                    }
                    ans+=(left*right);
                    i++;
                    j--;
                }
            }
            else if(sum<target)i++;
            else j--;
        }
        return ans;
    }
};