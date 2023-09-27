class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int>ans;
 
        int start = 0, end = m-1;
        int element1 = INT_MIN;
        int element2 = INT_MIN;
        int closestDiff = INT_MAX;
        while(start < n and end >= 0) {
            int sum = arr[start] + brr[end];
            int absDiff = abs(sum-x);
            if(absDiff < closestDiff){
                closestDiff = absDiff;
                element1 = arr[start];
                element2 = brr[end];
            }
            if(sum > x) {
                end--;
            } else {
                start++;
            }
        }
 
        ans.push_back(element1);
        ans.push_back(element2);
 
        return ans;
    }
};