class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        
        if(n%2 == 1){
            return false;
        }
        
        unordered_set<int> st;
        
        for(int i=0; i < n; i++) {
            int remain       = nums[i] % k;
            int other_remain = k - remain;
            
            if(st.find(other_remain) != st.end() || ( (remain == 0) && (st.find(0) != st.end() ))){
                st.erase(remain);
                st.erase(other_remain);
            }
            else{
                st.insert(remain);
            }
        }
        
        return st.size() == 0;
    }
};