class Solution {
  public:
     void mergeArrays(vector<int>& a, vector<int>& b) {

        int n=a.size(),m=b.size(),i=n-1,j=0;
        while(i>=0 && j<m){
            if(a[i]<=b[j])break;
            swap(a[i--],b[j++]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};