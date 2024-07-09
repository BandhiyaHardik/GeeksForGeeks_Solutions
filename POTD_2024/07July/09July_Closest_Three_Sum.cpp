class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {

        int diff=INT_MAX,ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-2;i++){
            int j=i+1,k=arr.size()-1;
            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                int d = abs(sum-target);
                if(d<diff){
                    diff=d;
                    ans=sum;
                }
                else if(d==diff){
                    ans=max(ans,sum);
                }
                if(sum<target)j++;
                else if(sum==target)return sum;
                else k--;
            }
        }
        return ans;
    }
};
