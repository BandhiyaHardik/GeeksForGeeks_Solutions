class Solution {
  public:
    // Function to find the majority elements in the array
     vector<int> findMajority(vector<int>& nums) {

        int n=nums.size(), can1=INT_MIN, can2=INT_MIN, counter1 = 0, counter2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==can1)counter1++;
            else if(nums[i]==can2)counter2++;
            else if(counter1==0){
                can1=nums[i];
                counter1=1;
            }
            else if(counter2==0){
                can2=nums[i];
                counter2=1;
            }
            else{
                counter1--;
                counter2--;
            }
        }
        int vote1=0,vote2=0;
        for(int x:nums){
            if(x==can1)vote1++;
            if(x==can2)vote2++;
        }
        vector<int> ans;
        if(vote1>n/3)ans.push_back(can1);
        if(vote2>n/3)ans.push_back(can2);
        if(ans.empty())ans.push_back(-1);
        return ans;
    }

};