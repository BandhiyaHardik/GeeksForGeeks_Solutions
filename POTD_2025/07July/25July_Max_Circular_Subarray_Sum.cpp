class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int total = 0, maxSum = arr[0], curMax = 0, minSum = arr[0], curMin = 0;
        for (int num : arr) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            total += num;
        }
        if (maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};