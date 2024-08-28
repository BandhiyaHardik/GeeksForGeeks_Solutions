class Solution {
  public:
     static bool func(pair<int,int> &a,pair<int,int> &b){
        if(a.second>b.second)return true;
        else if(a.second<b.second)return false;
        else return a.first<b.first;
    }
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {

        unordered_map<int,int> mm;
        vector<pair<int,int>> vec;
        vector<int> ans;
        for(auto x:arr)mm[x]++;
        for(auto x:arr)vec.push_back({x,mm[x]});
        sort(vec.begin(),vec.end(),func);
        for(auto x:vec)ans.push_back(x.first);
        return ans;
    }
};