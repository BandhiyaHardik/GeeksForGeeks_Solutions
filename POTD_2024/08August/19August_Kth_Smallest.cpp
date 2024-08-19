class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    
    int kthSmallest(vector<int> &arr, int k) {

       map<int,int> mp;
       for(int i=0;i<arr.size();i++){
           mp[arr[i]]++;
       }
       for(auto i:mp){
           k--;
           if(k==0) return i.first;
       }
       return 0;
    }
};