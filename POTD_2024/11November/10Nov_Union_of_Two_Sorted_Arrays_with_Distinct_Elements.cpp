class Solution {
  public:
  // a,b : the arrays
  // Function to return a list containing the union of the two arrays.
  vector<int> findUnion(vector<int> &a, vector<int> &b) {
      // return vector with correct order of elements
      set<int>st(a.begin(),a.end());
      for(int i:b) st.insert(i);
      vector<int> ans(st.begin(),st.end());
      return ans;
  }
};