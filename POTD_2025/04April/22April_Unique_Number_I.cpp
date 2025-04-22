class Solution {
  public:
    int findUnique(vector<int> &arr) {

        int ans=0;
        for(auto it:arr){
            ans^=it;
        }
        return ans;
    }
};