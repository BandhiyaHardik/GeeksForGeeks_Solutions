class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        long long int temp = 1, c = 0, index = -1, n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i])temp*=nums[i];
            else{
                c++;
                index=i;
            }
        }
        vector<long long int> ans(n,0);
        if(c>1)return ans;
        if(c==1){
            ans[index]=temp;
            return ans;
        }
        for(int i=0;i<n;i++){
            ans[i]=temp/nums[i];
        }
        return ans;
    }
};