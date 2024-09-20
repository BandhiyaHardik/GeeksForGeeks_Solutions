class Solution {
  public:
  // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {

        int count=1;
        int maxi=height[0];
        for(int i=1;i<height.size();i++){
            if(height[i]>maxi){
                count++;
                maxi=height[i];
            }
        }
        return count;
        
    }
};