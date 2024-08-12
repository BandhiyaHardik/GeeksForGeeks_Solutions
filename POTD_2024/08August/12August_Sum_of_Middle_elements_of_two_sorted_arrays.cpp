class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {

        int n = arr1.size(),low=0,high=n-1,mid=0;
        while(low<=high){
            mid=(low+high)/2;
            int midSecond = n-1-mid;
            int first1 = mid>0?arr1[mid-1]:INT_MIN;
            int second1 = arr1[mid];
            int first2 = midSecond>0?arr2[midSecond-1]:INT_MIN;
            int second2 = arr2[midSecond];
            int third1 = mid+1<n?arr1[mid+1]:INT_MAX;
            int third2 = midSecond+1<n?arr2[midSecond+1]:INT_MAX;
            int mx = max(second1,second2);
            if(mx<=third1 and mx<=third2){
                return mx+max(max(first1,first2),min(second1,second2));
            }
            else if(mx>third1){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return 0;
    }
};